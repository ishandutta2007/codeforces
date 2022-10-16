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

const int N = 1e5 + 5;

int n, a[N];
 
LL s[N];

bool f[N], g[N];

bool inline chk(int k) {
    for (int i = 1; i <= n; i++) g[i] = f[i], f[i] = 0;
    LL mx = -9e18;
    bool o = 0;
    for (int i = n; i; i--) {
        if (i + k >= 1 && g[i + k]) chkMax(mx, s[i + k - 2 + k] - s[i + k - 1]);
        if (s[i + k - 1] - s[i - 1] < mx) f[i] = 1, o = 1;
    }
    return o;
}

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]), s[i] = s[i - 1] + a[i];
        int k = 1;
        for (int i = 1; i <= n; i++) f[i] = 1;
        while (chk(k + 1)) k++;
        printf("%d\n", k);
        for (int i = 1; i <= n; i++) f[i] = g[i] = 0;
    }
    return 0;
}