#include <bits/stdc++.h>
using namespace std;
#define M 1001001
typedef long long ll;
const int mod = 1000000007;

int n, m;
ll fac[M], fac_[M];
int mn[M], mu[M];
int p[M], cnt;
ll gg[M];

ll POW(int a, int n) {
    ll s = 1;
    while (n) {
        if (n & 1) {
            s = 1ll * s * a % mod;
        }
        a = 1ll * a * a % mod;
        n >>= 1;
    }
    return s;
}

void init() {
    fac[0] = fac_[0] = 1;
    for (int i = 1; i < M; i++) {
        fac[i] = 1ll * fac[i-1] * i % mod;
    }
    fac_[M-1] = POW(fac[M-1], mod - 2);
    for (int i = M - 2; i >= 1; i--) {
        fac_[i] = 1ll * fac_[i+1] * (i + 1) % mod;
    }
    mn[1] = 1;
    mu[1] = 1;
    for (int i = 2; i < M; i++) {
        if (!mn[i]) {
            mn[i] = i;
            p[cnt++] = i;
            mu[i] = -1;
        } else {
            if (mn[i] == mn[i/mn[i]]) {
                mu[i] = 0;
            } else {
                mu[i] = -mu[i/mn[i]];
            }
        }
        for (int j = 0; j < cnt && i * p[j] < M; j++) {
            mn[i * p[j]] = p[j];
            if (i % p[j] == 0) {
                break;
            }
        }
    }
    for (int i = 1; i < M; i++) {
        for (int j = 1; i * j < M; j++) {
            if (!mu[j]) {
                continue;
            }
            gg[i * j] += mu[j] * i;
        }
    }
    for (int i = 1; i < M; i++) {
        if (i < 10) {
            //printf("g[%d] = %I64d\n", i, gg[i]);
        }
    }
}

int q[M], r[M], nq;
void bunhae(int x) {
    nq = 0;
    while (x > 1) {
        int c = mn[x];
        q[nq] = c;
        r[nq] = 0;
        while (mn[x] == c) {
            r[nq]++;
            x /= c;
        }
        nq++;
    }
}

int number[M];
void dfs(int cur, int d) {
    if (d == nq) {
        number[cur]++;
        return;
    }
    for (int i = 0; i <= r[d]; i++) {
        dfs(cur, d + 1);
        cur *= q[d];
    }
}

ll C(int a, int b) {
    if (a < b) {
        return 0;
    }
    return (1ll * fac[a] * fac_[b] % mod) * fac_[a-b] % mod;
}

ll answer;
void DFS(int cur, int d) {
    if (d == nq) {
        ll x = C(number[cur], m);
        number[cur]++;
        ll y = C(number[cur], m);
        y -= x;
        if (y < 0) {
            y += mod;
        }
        //printf("gg = %I64d, cur = %d, x = %I64d, y = %I64d, ; m = %d\n", gg[cur], cur, x, y, m);
        answer = (answer + y * gg[cur]) % mod;
        return;
    }
    for (int i = 0; i <= r[d]; i++) {
        DFS(cur, d + 1);
        cur *= q[d];
    }
}

int main() {
    //freopen("F1.in", "r", stdin);
    init();
    int Q;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &Q);
    for (int x, i = 1; i <= n; i++) {
        scanf("%d", &x);
        //printf("x = %d\n", x);
        bunhae(x);
        dfs(1, 0);
    }
    for (int x = 1; x < M; x++) if (number[x]) {
        answer += gg[x] * C(number[x], m);
        answer %= mod;
        //printf("number[%d] = %d\n", x, number[x]);
    }
    //printf("%I64d\n", answer);

    while (Q--) {
        int x;
        scanf("%d", &x);
        //printf("x = %d\n", x);
        bunhae(x);
        //printf("nq = %d\n", nq);
        DFS(1, 0);
        printf("%I64d\n", (answer%mod+mod)%mod);
        //return 0;
    }
    return 0;
}