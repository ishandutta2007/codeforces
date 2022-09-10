#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
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
using namespace std;

#define N 100007

int n, m, q, a, b, c;

VI G[N];

int p[N];
int comp[N];
int dp[N];
int c_diam[N];
int rozm[N];
VI v_diam[N];
VLL sum[N];

map<PII, double> M;

bool cmp(int a, int b)
{
	return dp[a]>dp[b];
}

void dfs1(int v)
{
	comp[v] = c;
	++rozm[c];

	for(int i = 0; i < G[v].size(); ++i)
	{
		if(p[v]==G[v][i])
		{
			swap(G[v][i], G[v].back());
			G[v].pop_back();
			break;
		}
	}

	for(auto it:G[v])
	{
		p[it] = v;
		dfs1(it);
		dp[v] = max(dp[v], dp[it]+1);
	}

	sort(ALL(G[v]), cmp);
}

void dfs2(int v, int d)
{
	v_diam[comp[v]].pb(max(dp[v], d));
	sum[comp[v]].pb(max(dp[v], d));
	c_diam[comp[v]] = max(c_diam[comp[v]], max(dp[v], d));

	for(int i = 0; i < G[v].size(); ++i)
	{
		if(i==0)
		{
			if(G[v].size()==1)
				dfs2(G[v][i], d+1);
			else
				dfs2(G[v][i], max(d+1, dp[G[v][1]]+2));
		}
		else
			dfs2(G[v][i], max(d+1, dp[G[v][0]]+2));
	}
}

void query(int a, int b)
{	
	a = comp[a];
	b = comp[b];

	if(a==b)
	{
		cout << -1 << endl;
		return;
	}

	if(mp(rozm[a], a)>mp(rozm[b], b))
		swap(a, b);

	if(M.find({a, b})!=M.end())
	{
		cout << M[{a, b}] << endl;
		return;
	}

	int base = max(c_diam[a], c_diam[b]);
	double ans = 0;

	for(auto it:v_diam[a])
	{
		int ind = upper_bound(ALL(v_diam[b]), base-it-1)-v_diam[b].begin();

		if(ind>0)
		{
			ans += (ll)ind*base;
			ans += sum[b].back()-sum[b][ind-1]+(ll)(v_diam[b].size()-ind)*(it+1);
		}
		else
			ans += sum[b].back()+(ll)v_diam[b].size()*(it+1);
	}

	ans /= (ll)v_diam[a].size()*v_diam[b].size();

	cout << ans << endl;

	M[{a, b}] = ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cout << setprecision(10) << fixed;

	cin >> n >> m >> q;

	while(m--)
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	
	for(int i = 1; i <= n; ++i)
	{
		if(!comp[i])
		{
			++c;
			dfs1(i);
			dfs2(i, 0);
		}
	}

	for(int i = 1; i <= c; ++i)
	{
		sort(ALL(v_diam[i]));
		sort(ALL(sum[i]));

		for(int j = 1; j < sum[i].size(); ++j)
		{
			sum[i][j] += sum[i][j-1];
		}
	}

	while(q--)
	{
		cin >> a >> b;
		query(a, b);
	}
}