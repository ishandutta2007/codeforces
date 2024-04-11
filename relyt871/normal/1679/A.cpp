#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 2005;

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
    LL n; read(n);
    if (n & 1) {
        puts("-1");
        return;
    }
    if (n < 4) {
        puts("-1");
        return;
    }
    LL tmp = n, mn = 0, mx = 0;
    while (tmp % 6 != 0) {
        tmp -= 4;
        ++mn;
    }
    mn += tmp / 6;
    tmp = n;
    while (tmp % 4 != 0) {
        tmp -= 6;
        ++mx;
    }
    mx += tmp / 4;
    printf("%lld %lld\n", mn, mx);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}