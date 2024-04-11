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

const int N = 1e6 + 5, P = 1e9 + 7;

int fact[N], infact[N];

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}
int inline C(int a, int b) {
    if (a < b || a < 0 || b < 0) return 0;
    return (LL)fact[a] * infact[b] % P * infact[a - b] % P;
}

void inline factPrework(int n) {
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (LL)fact[i - 1] * i % P;
    infact[n] = power(fact[n], P - 2);
    for (int i = n - 1; i; i--) infact[i] = infact[i + 1] * (i + 1ll) % P;
}
 
int n, m, k, pw2[N], inv2 = (P + 1) / 2;

int inline get(int n, int m) {
    return C(n - 1, n - m - 1);
}
int main() {
    factPrework(1e6);
    pw2[0] = 1;
    for (int i = 1; i < N; i++) pw2[i] = 1ll * pw2[i - 1] * inv2 % P;
    int T; read(T);
    while (T--) {
        read(n), read(m), read(k);
        if (n == m) {
            printf("%lld\n", 1ll * n * k % P);
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            int w = get(n - i, m - i);
            add(ans, 1ll * w * pw2[n - i] % P * (1ll * i * k % P) % P);
        }  
        printf("%d\n", ans);
    }
    return 0;
}