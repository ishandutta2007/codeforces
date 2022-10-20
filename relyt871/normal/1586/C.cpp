#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 1000005;

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

char s[MAXN];
int n, m, q, g[MAXN], sum[MAXN];

inline int ID(int x, int y) {
	return (x - 1) * m + y;
}

void solve() {
	read(n); read(m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; ++j) {
			if (s[j] == 'X') {
				g[ID(i, j)] = 1;
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= m; ++j) {
			if (g[ID(i - 1, j)] == 1 && g[ID(i, j - 1)] == 1) {
				sum[j] = 1;
			}
		}
	}
	for (int j = 1; j <= m; ++j) {
		sum[j] += sum[j - 1];
	}
	read(q);
	for (int i = 1, l, r; i <= q; ++i) {
		read(l); read(r);
		puts((sum[r] - sum[l])? "NO" : "YES");
	}
}

int main() {
	solve();
	return 0;
}