#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

#define mod(x) ((x)%Mod)

const ll Mod = 1000*1000*1000+7;

void add(ll &a, ll b) {
    a += b;
    if (a >= Mod) a -= Mod;
}

struct M {
    ll e[100][100];
    M operator*(M o) {
        M m;
        for (int i = 0; i < 100; i++) for (int j = 0; j < 100; j++) {
            m.e[i][j] = 0;
            for (int k = 0; k < 100; k++) {
                add(m.e[i][j], mod(e[i][k] * o.e[k][j]));
            }
        }
        return m;
    }
};

int n;
ll e;
ll a[105];

int count(ll k) {
    int c = 0;
    for (int i = 0; i < 60; i++) if (k & (1ll<<i)) c++;
    return c;
}

int main() {
    scanf("%d%lld", &n, &e);
    e--;
    for (int i = 0; i < n; i++) {
        scanf("%lld", a+i);
    }
    M m, t;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (i == 0 && j < n) {
                t.e[i][j] = 1;
            } else {
                t.e[i][j] = 0;
            }
            if (i < n && j < n && count(a[i] ^ a[j]) % 3 == 0) {
                m.e[i][j] = 1;
            } else {
                m.e[i][j] = 0;
            }
        }
    }
    for (int f = 0; f < 60; f++) {
        if (e & (1ll << f)) {
            t = t * m;
        }
        m = m * m;
    }

    ll ans = 0;
    for (int j = 0; j < 100; j++) {
        add(ans, t.e[0][j]);
    }
    printf("%lld\n", ans);
}