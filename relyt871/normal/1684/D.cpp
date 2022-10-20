#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 200005;

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

int n, k, a[MAXN];
LL ans, b[MAXN];

void solve() {
    read(n); read(k);
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        ans += a[i];
        b[i] = n - i - a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= k; ++i) {
        LL delta = b[i] - i + 1;
        if (delta >= 0) {
            break;
        }
        ans += delta;
    }
    printf("%lld\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}