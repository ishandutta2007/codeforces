#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 55;
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

int n, a[MAXN];
LL f[MAXN];

void solve() {
    read(n);
    for (int i = 1, x; i <= n; ++i) {
        read(x);
        a[x] = 1;
    }
    int ans = 0;
    for (int i = 1000000; i >= 1; --i) {
        int cnt = 0;
        for (int j = i; j <= 1000000; j += i) {
            cnt += a[j];
            f[i] -= f[j];
        }
        f[i] += 1LL * cnt * (cnt - 1) / 2;
        if (f[i] > 0 && !a[i]) {
            a[i] = 1;
            f[i] += cnt;
        }
        ans += a[i];
    }
    printf("%d\n", ans - n);
}

int main() {
	solve();
	return 0;
}