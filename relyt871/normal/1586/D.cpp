#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 105;

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

int n, to[N], deg[N], ans[N];

void solve() {
	read(n);
	for (int i = 2; i <= n; ++i) {
		printf("?");
		for (int j = 1; j <= n; ++j) {
			printf(" %d", 1 + (j == i));
		}
		printf("\n");
		fflush(stdout);
		int x; read(x);
		if (x && x < i) {
			to[i] = x;
			++deg[x];
		}
	}
	for (int i = 2; i <= n; ++i) {
		printf("?");
		for (int j = 1; j <= n; ++j) {
			printf(" %d", 1 + (j != i));
		}
		printf("\n");
		fflush(stdout);
		int x; read(x);
		if (x && x < i) {
			to[x] = i;
			++deg[i];
		}
	}
	int st = 0;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 0) {
			st = i; break;
		}
	}
	int num = 0;
	for (int u = st; u; u = to[u]) {
		ans[u] = ++num;
	}
	printf("!");
	for (int i = 1; i <= n; ++i) {
		printf(" %d", ans[i]);
	}
	printf("\n");
	fflush(stdout);
}

int main() {
	solve();
	return 0;
}