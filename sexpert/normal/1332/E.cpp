#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> mat;
const ll MOD = 998244353;

mat mul(mat A, mat B) {
    int n = A.size();
    mat C(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

mat id(int n) {
    mat C(n, vector<ll>(n));
    for(int i = 0; i < n; i++)
        C[i][i] = 1;
    return C;
}

mat matpow(mat A, ll e) {
    mat res = id(A.size());
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = mul(res, A);
        A = mul(A, A);
    }
    return res;
}

ll mpow(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, L, R;
    cin >> n >> m >> L >> R;
    if((n % 2) && (m % 2)) {
        cout << mpow(R - L + 1, m * n) << '\n';
        return 0;
    }
    ll ce = R/2 - (L - 1)/2, co = (R - L + 1) - ce;
    mat M = {{ce, co}, {co, ce}};
    M = matpow(M, (m * n) / 2LL);
    ll wo = M[0][0], we = M[1][0];
    cout << (wo * wo + we * we) % MOD << '\n';
}