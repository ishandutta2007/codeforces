#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<vector<ll>> mat;

const ll MOD = 1e9 + 7;

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

mat exp(mat A, ll e) {
    mat res = id(A.size());
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = mul(res, A);
        A = mul(A, A);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll k;
    cin >> n >> k;
    mat res(n, vector<ll>(n));
    vector<ll> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    if(k == 1) {
        cout << n << '\n';
        return 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(__builtin_popcountll(v[i] ^ v[j]) % 3 == 0)
                res[i][j] = 1;
        }
    }

    res = exp(res, k - 1);
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = (ans + res[i][j]) % MOD;
        }
    }

    cout << ans << '\n';
}