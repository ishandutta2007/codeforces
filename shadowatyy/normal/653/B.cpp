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
#define flush fflush(stdout)
using namespace std;

#define N 37

int n, q;

string a[N];
char b[N];

map<string, int> vis;
set<string> res;

void dfs(string s)
{
	vis[s] = 1;

	if(s.size()==n)
	{
		res.insert(s);
		return;
	}

	for(int i = 1; i <= q; ++i)
	{
		if(s[0]==b[i])
		{
			if(!vis[a[i]+s.substr(1, inf)])
				dfs(a[i]+s.substr(1, inf));
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;

	for(int i = 1; i <= q; ++i)
	{
		cin >> a[i] >> b[i];
	}

	dfs("a");

	cout << res.size();
}