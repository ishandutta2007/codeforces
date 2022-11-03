#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, M;
int a[90005];
int id[90005];
int pos[305][305];

void solve() {
	scanf("%d%d", &N, &M);
	rep(i, N * M) scanf("%d", a + i), id[i] = i;
	sort(id, id + N * M, [&] (int x, int y) { return make_pair(a[x], -x) < make_pair(a[y], -y); });
	rep(i, N * M) {
		int j = i;
		while (j < N * M - 1 && a[id[j + 1]] == a[id[j]]) ++j;
		int bgl = i / M, enl = j / M;
		if (bgl == enl) {
			rep(k, j - i + 1) pos[bgl][i % M + k] = id[i + k];
		}
		else {
			int pp = i;
			for (int k = 0; k <= j % M; ++k) pos[enl][k] = id[pp++];
			for (int l = enl - 1; l > bgl; --l) rep(k, M) pos[l][k] = id[pp++];
			for (int k = i % M; k < M; ++k) pos[bgl][k] = id[pp++];
		}
		i = j;
	}
	int ans = 0;
	rep(i, N) {
		rep(j, M) rep(k, j) ans += (pos[i][k] < pos[i][j]);
	}
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}