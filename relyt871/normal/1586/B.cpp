#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 100005;

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

int n, m, vis[MAXN];

void solve() {
	read(n); read(m);
	for (int i = 1; i <= n; ++i) {
		vis[i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		read(a); read(b); read(c);
		vis[b] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			for (int j = 1; j <= n; ++j) {
				if (j == i) continue;
				printf("%d %d\n", i, j);
			}
			return;
		}
	}
}

int main() {
	int T; read(T);
	while (T--) {
		solve();
	}
	return 0;
}