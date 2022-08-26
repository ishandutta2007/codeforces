#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// ========================================================================= //

const int N = 1111;

int n, m, maxw;
int w[N], b[N];
vector < int > e[N];
ll ans[N];

bool vis[N];
vector < ipair > u;
ipair dfs(int v)
{
	if (vis[v])
		return {0, 0};
	vis[v] = true;
	ipair cans = {w[v], b[v]};
	u.push_back(cans);
	for (int nv : e[v])
	{
		ipair nans = dfs(nv);
		cans.X += nans.X;
		cans.Y += nans.Y;
	}
	return cans;
}

int main()
{
    ios::sync_with_stdio(false);

	scanf("%d%d%d", &n, &m, &maxw);
	for (int i = 0; i < n; ++i)
		scanf("%d", w+i);
	for (int i = 0; i < n; ++i)
		scanf("%d", b+i);
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		--x;
		--y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	for (int i = 1; i <= maxw; ++i)
		ans[i] = -LINF;
	for (int i = 0; i < n; ++i)
	{
		if (vis[i])
			continue;
		u.clear();
		u.push_back(dfs(i));
		for (int j = maxw; j >= 0; --j)
			for (auto p : u)
				if (j - p.X >= 0)
					ans[j] = max(ans[j], ans[j-p.X] + p.Y);
	}

	ll anss = 0;
	for (int i = 0; i <= maxw; ++i)
		anss = max(anss, ans[i]);
	cout << anss << "\n";

    return 0;
}