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

const int N = 1005, P = 998244353;

int n, m, t, X[N], Y[N];

#define I __int128

I a[N];

vector<int> g[N];

void inline clr() {
    for (int i = 1; i <= n; i++) g[i].clear();
}

bool inline ok() {
    for (int i = 1; i <= n; i++) if (a[i]) return 0;
    return 1;
}

int K[N];

void inline wk() {
    for (int i = 1; i <= n; i++) K[i] = 0;
    for (int i = 1; i <= n; i++) if (a[i]) K[i]--;
    for (int i = 1; i <= m; i++) {
        int u = X[i], v = Y[i];
        if (a[u]) K[v]++;
    }
    I z = 1e36;
    for (int i = 1; i <= n; i++) {
        if (a[i] && K[i] < 0) {
            chkMin(z, a[i]);
        }
        if (!a[i] && K[i]) {
            chkMin(z, (I)1);
        }
    }
    t = (t + z) % P;
    for (int i = 1; i <= n; i++) a[i] = a[i] + K[i] * z;
}



int main() {
    int T; read(T);
    while (T--) {
        read(n), read(m);
        for (int i = 1; i <= n; i++) read(a[i]);
        for (int i = 1; i <= m; i++) {
            int u, v; read(u), read(v);
            g[u].pb(v);
            X[i] = u, Y[i] = v;
        }
        t = 0;
        while (!ok()) {
            wk();
        }
        printf("%d\n", t);
        clr();
    }   
    return 0;
}