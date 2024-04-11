#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 500005;

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
    int n, m;
    int rb, cb, rd, cd;
    read(n); read(m); read(rb); read(cb); read(rd); read(cd);
    int dr = 1, dc = 1, ans = 0;
    while (rb != rd && cb != cd) {
        if (rb + dr < 1 || rb + dr > n) dr = -dr;
        if (cb + dc < 1 || cb + dc > m) dc = -dc;
        rb += dr;
        cb += dc;
        ++ans;
    }
    printf("%d\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}