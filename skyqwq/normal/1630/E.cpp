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

const int N = 1e6 + 5, P = 998244353;

int n, a[N], c[N], cnt[N], o, fact[N], infact[N];

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}

void inline factPrework(int n) {
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (LL)fact[i - 1] * i % P;
    infact[n] = power(fact[n], P - 2);
    for (int i = n - 1; i; i--) infact[i] = infact[i + 1] * (i + 1ll) % P;
}

int inline C(int a, int b) {
    if (a < b || a < 0 || b < 0) return 0;
    return (LL)fact[a] * infact[b] % P * infact[a - b] % P;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
 
void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

void inline del(int &x, int y) {
    x -= y;
    if (x < 0) x += P;
}

PII inline calc2(int x) {
    int z = n / x;
    for (int i = 1; i <= n; i++)
        if (cnt[i] % z) return mp(0, 0);
    int s = n;
    int q = power(x * (x - 1ll) % P, P - 2);
    int oo = fact[x];
    for (int i = 1; i <= n; i++) {
        int t = cnt[i] / z;
        if (t) {
            oo = 1ll * oo * infact[cnt[i] / z] % P;
            int num = 1ll * t * (t - 1) % P * q % P;
            del(s, 1ll * n * num % P);
        }
    }
    s = 1ll * s * oo % P;
    return mp(s, oo);
}


int main() {
    factPrework(1e6);
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) cnt[i] = 0;
        o = 0;
        for (int i = 1; i <= n; i++) {
            read(a[i]), cnt[a[i]]++;
            if (cnt[a[i]] == n) o = 1;
        }
        if (o) {
            puts("1");
            continue;
        }
        for (int i = 0; i <= n; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[gcd(n, i)]++;
        int ans = 0, zs = 0;
        for (int i = 0; i <= n; i++) {
            if (c[i]) {
                if (true) {
                    PII oo = calc2(i);
                    add(ans, 1ll * c[i] * oo.fi % P);
                    add(zs, 1ll * c[i] * oo.se % P);
                }
                
               // cout << c[i] << ".." << i << "??" << calc(i) << endl;
            }
        }
        //cout << ans << "aa???\n";
        ans = 1ll * ans * power(zs, P - 2) % P;
        printf("%d\n", ans);
    }
    return 0;
}