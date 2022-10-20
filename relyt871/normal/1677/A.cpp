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

int n, p[N], sum[N][N];

int query(int l1, int r1, int l2, int r2) {
    return sum[r1][r2] - sum[l1 - 1][r2] - sum[r1][l2 - 1] + sum[l1 - 1][l2 - 1];
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(p[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            sum[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 2; j <= n; ++j) {
            if (p[i] > p[j]) {
                sum[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 2; j < n; ++j) {
            if (p[i] < p[j]) {
                ans += query(i + 1, j - 1, j + 1, n);
            }
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