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

const int N = 200005, P = 998244353;

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

int n, m, ans, cnt[N], val, c[N];

int s[N], t[N];

void inline Add(int x, int k) {
    if (k < 0) k += P;
    for (; x < N; x += x & -x) add(c[x], k);
}

int inline ask(int x) {
    int ret = 0;
    for (; x; x -= x & -x) add(ret, c[x]);
    return ret;
}

void inline mat(int x, int o) {
    if (cnt[x]) {
        int w = 1ll * fact[cnt[x]] * infact[cnt[x] - 1] % P * o;
        Add(x, w);
    }
} 

void inline add(int x) {
    val = 1ll * val * fact[cnt[x]] % P;
    mat(x, -1);
    cnt[x]++;
    mat(x, 1);
    val = 1ll * val * infact[cnt[x]] % P;
}

void inline del(int x) {
    val = 1ll * val * fact[cnt[x]] % P;
    mat(x, -1);
    cnt[x]--;
    mat(x, 1);
    val = 1ll * val * infact[cnt[x]] % P;
}

void inline work1() {
    val = 1;
    for (int i = 1; i <= n; i++) add(s[i]);
    for (int i = 1; i <= min(n, m); i++) {
        add(ans, 1ll * val * fact[n - i] % P * ask(t[i] - 1) % P);
        if (!cnt[t[i]]) break;
        del(t[i]);
    }
}

void inline work2() {
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) cnt[s[i]]++;
    for (int i = 1; i <= n; i++) {
        if (!cnt[t[i]]) return;
        cnt[t[i]]--;
    }
    add(ans, 1);
}

int main() {
    factPrework(N - 1);
    read(n), read(m);
    for (int i = 1; i <= n; i++) read(s[i]);
    for (int i = 1; i <= m; i++) read(t[i]);
    work1();
    if (n < m) work2();
    printf("%d\n", ans);
    return 0;
}