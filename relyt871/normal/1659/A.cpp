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

void solve() {
    int n, r, b;
    read(n); read(r); read(b);
    int len = r / (b + 1), rem = r % (b + 1);
    for (int i = 1; i <= rem; ++i) {
        for (int j = 1; j <= len + 1; ++j) {
            putchar('R');
        }
        putchar('B');
    }
    for (int i = 1; i <= b - rem; ++i) {
        for (int j = 1; j <= len; ++j) {
            putchar('R');
        }
        putchar('B');
    }
    for (int j = 1; j <= len; ++j) {
        putchar('R');
    }
    puts("");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}