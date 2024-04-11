#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 5005;

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
LL a[N], b[N];

LL Try(int p) {
    LL ret = 0;
    b[p] = 0;
    for (int i = p + 1; i <= n; ++i) {
        LL c = (b[i - 1] + a[i]) / a[i];
        ret += c;
        b[i] = c * a[i];
    }
    for (int i = p - 1; i >= 1; --i) {
        LL c = (b[i + 1] + a[i]) / a[i];
        ret += c;
        b[i] = c * a[i];
    }
    return ret;
}

void solve() {
    read(n);
    for (int i = 1; i<= n; ++i) {
        read(a[i]);
    }
    LL ans = Try(1);
    for (int i = 2; i <= n; ++i) {
        ans = min(ans, Try(i));
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}