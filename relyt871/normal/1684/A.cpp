#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
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

int n, mn, d[20], t;

void solve() {
    read(n);
    mn = 10;
    t = 0;
    while (n) {
        d[++t] = n % 10;
        n /= 10;
        mn = min(mn, d[t]);
    }
    if (t == 2) {
        printf("%d\n", d[1]);
        return;
    }
    printf("%d\n", mn);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}