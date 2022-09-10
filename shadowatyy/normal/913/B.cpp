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

const int N = 1007;

int n, ans = 1;

VI G[N];

void dfs(int v)
{
	int cnt = 0;

	for(auto it:G[v])
	{
		if(G[it].empty())
			++cnt;
		else
			dfs(it);
	}

	if(cnt<3)
		ans = 0;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 2; i <= n; ++i)
	{
		int p;
		cin >> p;
		G[p].pb(i);
	}

	dfs(1);

	if(ans)
		cout << "Yes";
	else
		cout << "No";
}