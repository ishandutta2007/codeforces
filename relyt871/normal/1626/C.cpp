#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int N = 105;
const LL INF = 0x3f3f3f3f3f3f3f3f;

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
LL k[N], h[N];
LL dp[N];

inline LL S(LL x) {
    return x * (x + 1) / 2;
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(k[i]);
    }
    for (int i = 1; i <= n; ++i) {
        read(h[i]);
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = INF;
        LL st = k[i] + 1;
        for (int j = i; j >= 1; --j) {
            st = min(st, k[j] - h[j] + 1);
            if (st > k[j - 1]) {
                dp[i] = min(dp[i], dp[j - 1] + S(k[i] - st + 1));
            }
        }
    }
    printf("%lld\n", dp[n]);
}

int main() {
	int T; read(T);
	while (T--) {
        solve();
	}
	return 0;
}