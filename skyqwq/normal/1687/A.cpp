// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, k, a[N];

LL s[N];

LL inline ask() {
    if (k >= n) {
        LL s = 0;
        for (int i = 1; i <= n; i++) s += a[i] + (k - i);
        return s;
    } else {
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
        LL mx = 0;
        for (int i = k; i <= n; i++) {
            chkMax(mx, s[i] - s[i - k] + k * (k - 1ll) / 2);
        }
        return mx;
    }
}

int main() {
    int T; read(T);
    while (T--) {
        read(n), read(k);
        for (int i = 1; i <= n; i++) read(a[i]);
        printf("%lld\n", ask());
    }
    return 0;
}