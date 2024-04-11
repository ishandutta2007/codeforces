#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N;
vector<int> nei[200005];
int tp[200005];
int buds, lvs;

void dfs(int now, int lst) {
	bool isbud = 0;
	for (int to : nei[now]) {
		if (to == lst) continue;
		dfs(to, now);
		if (!tp[to]) isbud = 1;
	}
	tp[now] = isbud;
	if (isbud) ++buds;
	else ++lvs;
}

void solve() {
	scanf("%d", &N);
	repi(i, N) nei[i].clear();
	repi(i, N - 1) {
		int u, v; scanf("%d%d", &u, &v);
		nei[u].push_back(v);
		nei[v].push_back(u);
	}
	buds = lvs = 0;
	dfs(1, 0);
	if (tp[1]) --buds;
	printf("%d\n", lvs - buds);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}