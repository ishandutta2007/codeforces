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

int n;
LL a, b, x[MAXN];

void solve() {
    read(n); read(a); read(b);
    for (int i = 1; i <= n; ++i) {
        read(x[i]);
    }
    LL sum = 0, ans = 1e18;
    for (int i = n; i >= 0; --i) {
        ans = min(ans, a * x[i] + b * x[i] + b * (sum - x[i] * (n - i)));
        sum += x[i];
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