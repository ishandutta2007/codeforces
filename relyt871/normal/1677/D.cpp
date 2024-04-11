#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
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

int n, k, v[MAXN], q[MAXN], head, tail;
int lim[MAXN], must[MAXN];

void solve() {
    read(n); read(k);
    for (int i = 1; i <= n; ++i) {
        read(v[i]);
        must[i] = 0;
        lim[i] = n + n;
    }
    for (int i = 1; i <= n; ++i) {
        if (v[i] > 0) {
            if (i + k > n) {
                puts("0");
                return;
            }
            must[i + k] = v[i] + k;
        } else if (v[i] == 0) {
            if (i + k <= n) {
                lim[i + k] = v[i] + k;
            }
        }
    }
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (must[i]) {
            if (must[i] > i - 1) {
                puts("0");
                return;
            }
            continue;
        }
        ans = 1LL * ans * min(i, lim[i] + 1) % 998244353;
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