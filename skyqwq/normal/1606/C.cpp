// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
int n, k, a[11], s[11];

LL pw[20];

int main() {
    pw[0] = 1;
    for (int i = 1; i < 19; i++) pw[i] = pw[i - 1] * 10;
    int T; read(T);
    while (T--) {
        read(n), read(k); ++k;
        for (int i = 1; i <= n; i++) read(a[i]);
        LL ans = 0;
        LL mx = 0;
        for (int i = 1; i < n; i++) s[i] = pw[a[i + 1] - a[i]] - 1, mx += s[i];
        for (int i = n; i; i--) {
            if (k > mx) {
                LL t = k - mx;
                k -= t;
                ans += pw[a[i]] * t;
            }
            mx -= s[i - 1];
        }
        printf("%lld\n", ans);
    }
    return 0;
}