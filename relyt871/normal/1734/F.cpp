#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

LL n, m;
LL dp[70][2][2][2];

LL DP(int p, int full, int carry, int cnt) {
    if (p < 0) return (!carry && !cnt);
    LL &ret = dp[p][full][carry][cnt];
    if (ret != -1) return ret;
    ret = 0;
    int lim = (full? ((m >> p) & 1) : 1);
    for (int i = 0; i <= lim; ++i) {
        for (int j = 0; j < 2; ++j) {
            int sum = i + j + ((n >> p) & 1);
            if (carry ^ (sum > 1)) continue;
            ret += DP(p - 1, full & (i == lim), j, cnt ^ i ^ (sum & 1));
        }
    }
    return ret;
}

void solve() {
    read(n); read(m); --m;
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", DP(62, 1, 0, 1));
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}