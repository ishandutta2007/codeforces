#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) (int)(x).size()
using namespace std;

int n, m, res;

map<string, int> M;

string s;

vector<string> t = {"a", "b", "c", "d", "e", ""};

void solve()
{
	vector<string> w, que;

	int last = -1;

	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i]=='?')
		{
			w.pb(s.substr(last+1, i-last-1));
			last = i;
		}
	}

	w.pb(s.substr(last+1, s.size()-last-1));

	if(w.size()==1)
		que.pb(w[0]);
	else if(w.size()==2)
	{
		for(auto i:t)
		{
			que.pb(w[0]+i+w[1]);
		}
	}
	else if(w.size()==3)
	{
		for(auto i:t)
		{
			for(auto j:t)
			{
				que.pb(w[0]+i+w[1]+j+w[2]);
			}
		}
	}
	else if(w.size()==4)
	{
		for(auto i:t)
		{
			for(auto j:t)
			{
				for(auto k:t)
				{
					que.pb(w[0]+i+w[1]+j+w[2]+k+w[3]);
				}
			}
		}
	}

	sort(ALL(que));
	que.erase(unique(ALL(que)), que.end());

	for(auto it:que)
		res += M[it];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> s;
		++M[s];
	}

	for(int i = 1; i <= m; ++i)
	{
		res = 0;
		cin >> s;
		solve();
		cout << res << endl;
	}

	
}