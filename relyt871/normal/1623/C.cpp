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

int n;
LL h[MAXN], a[MAXN];

bool Check(LL mid) {
    for (int i = 1; i <= n; ++i) {
        a[i] = h[i];
    }
    for (int i = n; i >= 3; --i) {
        if (a[i] < mid) return 0;
        LL d = min(h[i], a[i] - mid) / 3;
        a[i] -= d * 3;
        a[i - 1] += d;
        a[i - 2] += d * 2;
    }
    return (a[1] >= mid && a[2] >= mid);
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(h[i]);
    }
    LL L = 1, R = 1e9, ans = 0;
    while (L <= R) {
        LL mid = (L + R) >> 1;
        if (Check(mid)) {
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
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