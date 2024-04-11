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
const int M = 1<<14;

int n, q;

VI load[2*M];

bitset<N> dp[2*M];
bitset<N> ans;

void insert(int a, int b, int c, int v = 1, int l = 0, int r = M-1)
{
	if(a>r || l>b)
		return;

	if(a<=l && r<=b)
	{
		load[v].pb(c);
		return;
	}

	insert(a, b, c, 2*v, l, (l+r)/2);
	insert(a, b, c, 2*v+1, (l+r)/2+1, r);
}

void dfs(int v)
{
	for(auto it:load[v])
	{
		dp[v] |= dp[v]<<it;
	}

	if(v>=M)
	{
		ans |= dp[v];
		return;
	}

	dp[2*v] = dp[2*v+1] = dp[v];
	dfs(2*v);
	dfs(2*v+1);
}	

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;

	while(q--)
	{
		int l, r, x;
		cin >> l >> r >> x;
		insert(l, r, x);
	}

	dp[1][0] = 1;
	dfs(1);

	int cnt = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(ans[i])
			++cnt;
	}

	cout << cnt << endl;

	for(int i = 1; i <= n; ++i)
	{
		if(ans[i])
			cout << i << " ";
	}
}