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

int n, m;
bool vis[1000010];
int p[1000010];
vi g[1000010];
vi col[1000010];
vi num[1000010];
int ans[1000010];

void dfs(int v, int k)
{
    col[k].pb(v);
    num[k].pb(p[v]);

    vis[v] = 1;
    for (int to : g[v]) if (!vis[to]) dfs(to, k);
}

int main() {
    scanf("%d %d", &n, &m);
    rep(i, n) scanf("%d", &p[i]);

    rep(i, m) {
	int a, b;
	scanf("%d %d", &a, &b);
	--a; --b;
	g[a].pb(b);
	g[b].pb(a);
    }

    int now = 0;

    rep(i, n) if (!vis[i]) {
	dfs(i, now++);
    }

    rep(i, now) {
	sort(ALL(col[i]));
	sort(ALL(num[i]));
	reverse(ALL(num[i]));

	rep(j, num[i].size()) {
	    ans[col[i][j]] = num[i][j];
	}
    }

    rep(i, n) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');

    return 0;
}