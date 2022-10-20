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

int n, x, a[MAXN], b[MAXN];

void solve() {
	read(n); read(x);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	if (n - x >= x + 1) {
		puts("YES");
		return;
	}
	int p = 0, q = 0;
	for (int i = 1; i <= n - x; ++i) {
		b[++p] = a[i];
	}
	for (int i = x + 1; i <= n; ++i) {
		b[++p] = a[i];
	}
	sort(b + 1, b + p + 1);
	for (int i = 1; i <= n - x; ++i) {
		a[i] = b[++q];
	}
	for (int i = x + 1; i <= n; ++i) {
		a[i] = b[++q];
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i + 1]) {
			puts("NO");
			return;
		}
	}
	puts("YES");
}

int main() {
	int T; read(T);
	while (T--) {
		solve();
	}
	return 0;
}