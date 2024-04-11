#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
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

int n, l, cnt[100];

void solve() {
    read(n); read(l);
    for (int i = 0; i < l; ++i) {
        cnt[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        int x; read(x);
        for (int j = 0; j < l; ++j) {
            if ((x >> j) & 1) {
                ++cnt[j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < l; ++i) {
        if (cnt[i] > n - cnt[i]) {
            ans |= (1 << i);
        }
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