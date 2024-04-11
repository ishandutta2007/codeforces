// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 66;

int n, a[N];
 
int main() {
    int T; read(T);
    while (T--) {
        read(n);
        int c0 = 0, c1 = 0;
        for (int i = 1; i <= n; i++) read(a[i]), c0 += a[i] == 0, c1 += a[i] == 1;
        LL ans = (1ll << c0) * c1;
        printf("%lld\n", ans);
    }
    return 0;
}