#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define check(a) cout << a << endl;
#define CHECK cout << "wow" << endl;
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

int n;
char s[MAXN];

void solve() {
	read(n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '0') {
			if (i <= n / 2) {
				printf("%d %d %d %d\n", i, n, i + 1, n);
			} else {
				printf("%d %d %d %d\n", 1, i, 1, i - 1);
			}
			return;
		}
	}
	printf("%d %d %d %d\n", 1, n - 1, 2, n);
}

int main() {
	int T; read(T);
	while (T--) {
		solve();
	}
	return 0;
}