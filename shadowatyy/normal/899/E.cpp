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

const int N = 2e5+7;

int n, res;

int a[N];

int len[N];
int col[N];

struct comp
{
	bool operator()(int a, int b)
	{
		return mp(len[a], -a)>mp(len[b], -b);
	}
};

set<int, comp> Q;
set<int> S;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = n; i >= 1; --i)
	{
		++len[i];

		if(a[i-1]!=a[i])
		{
			col[i] = a[i];
			Q.insert(i);
			S.insert(i);
		}
		else
			len[i-1] += len[i];
	}

	while(!Q.empty())
	{
		++res;
		int v = *Q.begin();
		Q.erase(Q.begin());

		auto it = S.find(v);

		if(it!=S.begin() && next(it)!=S.end())
		{
			int a = *prev(it), b = *next(it);

			if(col[a]==col[b])
			{
				S.erase(b);
				Q.erase(b);
				Q.erase(a);
				len[a] += len[b];
				Q.insert(a);
			}
		}
		
		S.erase(it);
	}	

	cout << res;
}