#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n, mc;
int c[200010];
vi g[200010];

void dfs(int v, int p, int ng)
{
	int cc = 0;

	for (int to : g[v]) if (to != p) {
		while (cc == ng || cc == c[v]) ++cc;
		c[to] = cc++;
		dfs(to, v, c[v]);
	}
}

int main() {
	cin >> n;

	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].pb(b); g[b].pb(a);
	}

	rep(i, n) mc = max(mc, (int)g[i].size() + 1);
	dfs(0, -1, -1);

	printf("%d\n", mc);
	rep(i, n) printf("%d%c", c[i] + 1, i == n - 1 ? '\n' : ' ');

	return 0;
}