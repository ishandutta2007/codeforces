#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main() {
#ifdef local
	freopen("a.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, K, Q;
		scanf("%d%d%d%d", &n, &m, &K, &Q);
		vector<int> x(Q), y(Q);
		rep(i, 0, Q - 1) {
			scanf("%d%d", &x[i], &y[i]);
			--x[i], --y[i];
		}
		const int P = 998244353;
		int cntx = 0, cnty = 0, ret = 1;
		vector<bool> usedx(n), usedy(m);
		per(i, Q - 1, 0) {
			if (cntx == n || cnty == m) break;
			int fx = 0, fy = 0;
			if (!usedx[x[i]]) {
				fx = 1;
				usedx[x[i]] = 1;
				++cntx;
			}
			if (!usedy[y[i]]) {
				fy = 1;
				usedy[y[i]] = 1;
				++cnty;
			}
			if (fx || fy) {
				ret = 1LL * ret * K % P;
			}
		}
		printf("%d\n", ret);
	}
}