#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define foreach(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<int> nei[500005];
vector<int> ceng[500005];
int cs, fa[500005], cn[500005];
bool lgl[500005];

void dfs(int now, int lst, int cg) {
	ceng[cg].pub(now); fa[now] = lst;
	cs = max(cs, cg); cn[now] = cg;
	lgl[now] = 1;
	for (int to : nei[now]) {
		if (lgl[to]) continue;
		dfs(to, now, cg + 1);
	}
}

void solve() {
	cont(i, cs) ceng[i].clear();
	scanf("%d%d", &n, &m);
	cont(i, n) lgl[i] = 0, nei[i].clear();
	cont(i, m) {
		int a, b; scanf("%d%d", &a, &b);
		nei[a].pub(b); nei[b].pub(a);
	}
	cs = 0; dfs(1, 0, 1);
	cont(i, n) {
		if (cn[i] >= (n + 1) / 2) {
			puts("PATH");
			printf("%d\n", cn[i]);
			int cur = i;
			while (cur) {
				printf("%d%c", cur, " \n"[cur == 1]);
				cur = fa[cur];
			}
			return;
		}
	}
	puts("PAIRING");
	vector<pair<int, int> > pr;
	cont(i, cs) range(j, 0, SZ(ceng[i]) - 2, 2) pr.emb(ceng[i][j], ceng[i][j + 1]);
	printf("%d\n", SZ(pr));
	for (auto it : pr) printf("%d %d\n", it.first, it.second);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}