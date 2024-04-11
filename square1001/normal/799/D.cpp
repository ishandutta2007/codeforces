#include <map>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, a, b, h, w, x[100009]; bool dp[100009];
struct state { int pos, p, q; };
bool operator<(const state& s1, const state& s2) {
	if (s1.pos != s2.pos) return s1.pos < s2.pos;
	if (s1.p != s2.p) return s1.p < s2.p;
	return s1.q < s2.q;
}
int main() {
	scanf("%d %d %d %d %d", &a, &b, &h, &w, &n);
	int ret = -1;
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);
	sort(x, x + n, greater<int>());
	for(int t = 0; t < 2; t++) {
		int H = (a + h - 1) / h, W = (b + w - 1) / w;
		map<state, bool> vis; vis[state{ 0, 1, 1 }] = true;
		queue<state> que; que.push(state{ 0, 1, 1 });
		bool flag = false;
		while (!que.empty()) {
			state u = que.front(); que.pop();
			if (u.p == H && u.q == W) {
				if (ret == -1) ret = u.pos;
				else ret = min(ret, u.pos);
				break;
			}
			if (u.pos != n) {
				state v1 = state{ u.pos + 1, (int)min(1LL * u.p * x[u.pos], 1LL * H), u.q };
				state v2 = state{ u.pos + 1, u.p, (int)min(1LL * u.q * x[u.pos], 1LL * W) };
				if (!vis[v1]) vis[v1] = true, que.push(v1);
				if (!vis[v2]) vis[v2] = true, que.push(v2);
			}
		}
		swap(a, b);
	}
	printf("%d\n", ret);
	return 0;
}