#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 300005;

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

int n, k;
LL b[MAXN], ed[MAXN];

void solve() {
    read(n); read(k);
    for (int i = 1; i <= n; ++i) {
        read(b[i]);
    }
    LL ans = 0, add = 0, cnt = 0;
    for (int i = n; i >= 1; --i) {
        add -= cnt;
        cnt -= ed[i];
        int kk = min(i, k);
        LL need = max(0LL, b[i] - add);
        LL use = (need + kk - 1) / kk;
        ans += use;
        add += use * kk;
        cnt += use;
        ed[i - kk] += use;
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}