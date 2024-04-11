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

int n, m;
LL k, a[MAXN], sum[MAXN];

inline int Calc(LL base) {
    int L = 2, R = n + 1, ret = 1;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (base + sum[mid - 1] +  base * (n - mid + 1) <= k) {
            ret = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    if (base != a[1]) {
        return n - ret + 1;
    } else {
        return min(n - ret + 1, n - m);
    }
}

void solve() {
    read(n); read(k);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    sort(a + 1, a + n + 1);
    m = 1;
    while (m < n && a[m + 1] == a[1]) ++m;
    for (int i = 2; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }
    LL start = min(a[1], k / n);
    LL ans = llabs(a[1] - start) + n;
    for (LL i = start; i >= start - n; --i) {
        ans = min(ans, llabs(a[1] - i) + Calc(i));
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