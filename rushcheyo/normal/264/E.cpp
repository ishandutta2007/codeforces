#include <bits/stdc++.h>
using namespace std;

const int N = 200025;
const int D = 1 << 18;
int m, xt[N], yt[N], st[15], dp[N];
priority_queue<int, vector<int>, greater<int>> q;

struct segtree {
	int ma[D * 2 + 10];
	void upd(int x, int v) {
		int p = D + x - 1;
		ma[p] = v;
		while (p >>= 1) ma[p] = max(ma[p << 1], ma[p << 1 | 1]);
	}

	int query(int x) {
		if (x == 0) return ma[1];
		int p = D + x - 1, ret = 0;
		for (; p != 1; p >>= 1) if (!(p & 1)) ret = max(ret, ma[p + 1]);
		return ret;
	}
} sx, sy;

int main() {
	scanf("%*d%d", &m);
	while (m--) {
		int op, x, y, rk;
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &x, &y);
			y += m + 1;
			xt[x] = y;
			yt[y] = x;
			q.push(x);
			int top = 0;
			for (int i = y - 10; i <= y; i++)
				if (yt[i]) {
					st[top++] = i;
					if (i < y) sx.upd(yt[i], 0), sy.upd(i, 0);
				}
			while (top--) {
				int t = st[top];
				dp[yt[t]] = sx.query(yt[t]) + 1;
				sx.upd(yt[t], dp[yt[t]]);
				sy.upd(t, dp[yt[t]]);
			}
		} else {
			scanf("%d", &rk);
			int top = 0;
			for (int i = 1; i <= rk; i++) {
				int x = q.top(); q.pop();
				sx.upd(x, 0), sy.upd(xt[x], 0);
				if (i < rk) st[top++] = x;
				else xt[x] = yt[xt[x]] = 0;
			}
			while (top--) {
				int t = st[top];
				dp[t] = sy.query(xt[t]) + 1;
				sx.upd(t, dp[t]);
				sy.upd(xt[t], dp[t]);
				q.push(t);
			}
		}
		printf("%d\n", sx.query(0));
	}
	return 0;
}