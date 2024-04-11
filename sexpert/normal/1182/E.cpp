#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> mat;

// 1 1 1
// 1 0 0
// 0 1 0

// 1 -2 0 -1 1
// 1  0 0  0 0
// 0  1 0  0 0
// 0  0 1  0 0
// 0  0 0  1 0

const ll MOD = 1e9 + 7;
const ll EMOD = 1e9 + 6;
mat m1 = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
mat m2 = {{3, -2, 0, -1, 1}, {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 0}};

ll mpow(ll b, ll e) {
    if(e == 0) return 1;
    if(e % 2) return (b * mpow(b, e - 1))%MOD;
    ll p = mpow(b, e / 2);
    return (p * p)%MOD;
}

mat mul(mat A, mat B) {
    int n = A[0].size();
    mat res(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % EMOD;
            }
        }
    }
    return res;
}

mat matpow(mat X, ll e) {
    if(e == 1) return X;
    if(e % 2) return mul(X, matpow(X, e - 1));
    mat M = matpow(X, e / 2);
    return mul(M, M);
}

int main() {
    ll n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;

    ll ep = n - 3;
    ll res = 1;
    mat M = matpow(m1, ep);

    res = (res * mpow(f1, M[0][2])) % MOD;
    res = (res * mpow(f2, M[0][1])) % MOD;
    res = (res * mpow(f3, M[0][0])) % MOD;

    ll ex;
    if(n == 4)
        ex = 2;
    if(n == 5)
        ex = 6;
    if(n >= 6) {
        ep = n - 5;
        mat M = matpow(m2, ep);

        ex = (6*M[0][0] + 2*M[0][1])%EMOD;
    }
    if(ex < 0) ex += EMOD;
    res = (res * mpow(c, ex)) % MOD;
    cout << res << '\n';
}