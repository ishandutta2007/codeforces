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

int n, m, k;
bool vis[200010];
vi g[200010];
vi vs;

void dfs(int v)
{
	vis[v] = 1;
	vs.pb(v);
	for (int to : g[v]) if (!vis[to]) {
		dfs(to);
		vs.pb(v);
	}
}

int main() {
	cin >> n >> m >> k;

	rep(i, m) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].pb(b); g[b].pb(a);
	}

	dfs(0);

	int pt = 0;
	rep(i, k) {
		int zan = (n * 2 + k - 1) / k;
		vi go;

		while (zan > 0 && pt < vs.size()) {
			--zan;
			go.pb(vs[pt++]);
		}

		if ((int)go.size() == 0) {
			puts("1 1");
		} else {
			printf("%d", (int)go.size());
			rep(i, go.size()) printf(" %d", go[i] + 1);			
			puts("");
		}
	}

	return 0;
}