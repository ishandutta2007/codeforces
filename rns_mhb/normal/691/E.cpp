#include <bits/stdc++.h>
using namespace std;

#define N 105

typedef long long ll;
const int mod = 1e9 + 7;

int n;
ll k;
ll a[N];

struct mat{
    int a[N][N];
    mat operator* (const mat &b) const {
        mat rtn;
        for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++) {
            rtn.a[i][j] = 0;
            for (int k = 0; k < n; k ++) {
                (rtn.a[i][j] += 1ll * a[i][k] * b.a[k][j] % mod) %= mod;
            }
        }
        return rtn;
    }
} I, G;

mat powmat(mat a, ll b) {
    mat rtn = I;
    for (; b; b >>= 1, a = a * a) {
        if (b & 1) rtn = rtn * a;
    }
    return rtn;
}

int ans;

int main() {
    scanf("%d %I64d", &n, &k);
    for (int i = 0; i < n; i ++) scanf("%I64d", &a[i]);
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < n; j ++) {
        I.a[i][j] = i == j;
        G.a[i][j] = __builtin_popcountll(a[i] ^ a[j]) % 3 == 0;
    }
    G = powmat(G, k - 1);
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < n; j ++) (ans += G.a[i][j]) %= mod;
    printf("%d\n", ans);
    return 0;
}