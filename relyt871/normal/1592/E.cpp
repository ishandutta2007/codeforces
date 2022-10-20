#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 2000006;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

int n, a[MAXN], b[MAXN], c[MAXN], l[MAXN], nxt[MAXN], lst[2][MAXN], pos[2][MAXN], ans;

void Calc(int bit) {
	int mask = ((1 << 20) - 1) ^ ((1 << (bit + 1)) - 1);
	for (int i = 1; i <= n; ++i) {
		b[i] = ((a[i] >> bit) & 1);
		c[i] = (c[i - 1] ^ (a[i] & mask));
		nxt[i] = 0;
	}
	for (int i = 0; i < (1 << 20); ++i) {
		lst[0][i] = lst[1][i] = pos[0][i] = pos[1][i] = -1;
	}
	lst[0][0] = pos[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		l[i] = i;
		if (b[i] && b[i - 1]) {
			l[i] = l[i - 1];
		}
		if (lst[i & 1][c[i]] != -1) {
			nxt[lst[i & 1][c[i]]] = i;
		}
		lst[i & 1][c[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		if (pos[i & 1][c[i]] == -1) {
			pos[i & 1][c[i]] = i;
		}
		if (!b[i]) continue;
		while (pos[i & 1][c[i]] < l[i] - 1) {
			pos[i & 1][c[i]] = nxt[pos[i & 1][c[i]]];
		}
		ans = max(ans, i - pos[i & 1][c[i]]);
	}
}

void solve() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	ans = 0;
	for (int i = 19; i >= 0; --i) {
		Calc(i);
	}
	printf("%d\n", ans);
}

int main() {
	solve();
	return 0;
}