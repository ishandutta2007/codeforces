#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, M;
int a[1005], b[1005];
vector<int> nei[1005];
bool lgl[1005];
bool in[1005];
ll nhp;

bool dfs(int now, int lst, ll hp) {
	if (hp < a[now]) return 0;
	lgl[now] = 1;
	rep(i, SZ(nei[now])) {
		int to = nei[now][i];
		if (to == lst) continue;
		if (lgl[to] || in[to]) return nhp = hp + b[now], in[now] = 1, 1;
		if (dfs(to, now, hp + b[now])) {
			in[now] = 1;
			return 1;
		}
	}
	return 0;
}

bool check(ll hp) {
	memset(in, 0, sizeof(in));
	in[1] = 1;
	while (1) {
		memset(lgl, 0, sizeof(lgl));
		bool fnd = 0;
		repi(i, N) if (in[i]) {
			rep(j, SZ(nei[i])) {
				int to = nei[i][j];
				if (in[to]) continue;
				if (dfs(to, i, hp)) {
					fnd = 1;
					hp = nhp;
					goto Brk;
				}
			}
		}
		Brk:
		if (!fnd) break;
	}
	repi(i, N) if (!in[i]) return 0;
	return 1;
}

void solve() {
	scanf("%d%d", &N, &M);
	repi(i, N) nei[i].clear();
	repi(i, N - 1) scanf("%d", a + i + 1), ++a[i + 1];
	repi(i, N - 1) scanf("%d", b + i + 1);
	rep(i, M) {
		int u, v; scanf("%d%d", &u, &v);
		nei[u].push_back(v);
		nei[v].push_back(u);
	}
	int L = -1, R = 1e9 + 1;
	while (R - L > 1) {
		int m = (L + R) >> 1;
		if (check(m)) R = m;
		else L = m;
	}
	printf("%d\n", R);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}