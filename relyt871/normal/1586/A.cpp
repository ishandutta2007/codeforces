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

int n, a[MAXN];

inline bool NotPrime(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) return 1;
	}
	return 0;
}

void solve() {
	read(n);
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
		sum += a[i];
	}
	if (NotPrime(sum)) {
		printf("%d\n", n);
		for (int i = 1; i <= n; ++i) {
			printf("%d ", i);
		}
		printf("\n");
	} else {
		bool flag = 1;
		printf("%d\n", n - 1);
		for (int i = 1; i <= n; ++i) {
			if ((a[i] & 1) && flag) {
				flag = 0;
				continue;
			}
			printf("%d ", i);
		}
		printf("\n");
	}
}

int main() {
	int T; read(T);
	while (T--) {
		solve();
	}
	return 0;
}