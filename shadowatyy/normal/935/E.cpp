#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

const int N = 1e4+7;

int n, P, M, mul = 1, mq = -inf, pq = inf;

bool inv;

string s;

int pref[N];
int kon[N];
int ans[N];
int dp_min[N][107];
int dp_max[N][107];

stack<int> S;

inline int & get_min(int a, int p)
{
	if(P<=M)
	{	
		if(0<=p && p<=100)
			return dp_min[a][p];
		else
			return pq;
	}
	else
	{
		if(0<=pref[kon[a]]-pref[a-1]-p && pref[kon[a]]-pref[a-1]-p<=100)
			return dp_min[a][pref[kon[a]]-pref[a-1]-p];
		else
			return pq;
	}
}

inline int & get_max(int a, int p)
{
	if(P<=M)
	{	
		if(0<=p && p<=100)
			return dp_max[a][p];
		else
			return mq;
	}
	else
	{
		if(0<=pref[kon[a]]-pref[a-1]-p && pref[kon[a]]-pref[a-1]-p<=100)
			return dp_max[a][pref[kon[a]]-pref[a-1]-p];
		else
			return mq;
	}
}

void go(int a)
{
	if(a==kon[a])
	{
		get_max(a, 0) = get_min(a, 0) = s[a]-'0';
		return;
	}

	go(a+1);
	go(kon[a+1]+2);

	int all = pref[kon[a]]-pref[a-1];

	for(int p = max(0, all-M); p <= min(all, P); ++p)
	{
		for(int i = 0; i <= p-1; ++i)
		{
			get_min(a, p) = min(get_min(a, p), get_min(a+1, i)+get_min(kon[a+1]+2, p-1-i));
			get_max(a, p) = max(get_max(a, p), get_max(a+1, i)+get_max(kon[a+1]+2, p-1-i));
		}

		if(p<all)
		{
			for(int i = 0; i <= p; ++i)
			{
				get_min(a, p) = min(get_min(a, p), get_min(a+1, i)-get_max(kon[a+1]+2, p-i));
				get_max(a, p) = max(get_max(a, p), get_max(a+1, i)-get_min(kon[a+1]+2, p-i));
			}
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s >> P >> M;
	n = s.size();
	s = '#'+s;

	for(int i = 1; i <= n; ++i)
	{
		if(s[i]=='(')
			S.push(i);
		else if(s[i]==')')
		{
			kon[S.top()] = i;
			S.pop();
		}
		else if(s[i]!='?')
			kon[i] = i;
		else
			++pref[i];

		pref[i] += pref[i-1];
	}

	for(int i = 1; i <= n; ++i)
	{	
		for(int j = 0; j <= 100; ++j)
		{
			dp_min[i][j] = inf;
			dp_max[i][j] = -inf;
		}
	}

	go(1);

	cout << get_max(1, P) << endl;
}