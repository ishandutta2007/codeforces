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

void solve() {
	int l, r;
	read(l); read(r);
	if (l == r) {
		printf("0\n");
	} else {
		if (l > r / 2) {
			printf("%d\n", r % l);
		} else {
			if (r & 1) {
				printf("%d\n", r / 2);
			} else {
				printf("%d\n", r / 2 - 1);
			}
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