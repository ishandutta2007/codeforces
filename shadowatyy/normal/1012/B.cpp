#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vpii = vector<pii>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

const int N = 4e5+7;

int n, m, q, ans;

int r[N];
int c[N];

vi G[N];

bitset<N> vis;

void dfs(int v)
{
	vis[v] = 1;

	for(auto it:G[v])
	{
		if(!vis[it])
			dfs(it);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> q;

	for(int i = 1; i <= q; ++i)
	{
		cin >> r[i] >> c[i];
		G[r[i]].pb(c[i]+n);
		G[c[i]+n].pb(r[i]);
	}

	for(int i = 1; i <= n+m; ++i)
	{
		if(!vis[i])
		{
			++ans;
			dfs(i);
		}
	}

	cout << ans-1 << endl;
}