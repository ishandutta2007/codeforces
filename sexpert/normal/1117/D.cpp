    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef vector<vector<ll>> mat;
     
    const ll MOD = 1e9 + 7;
     
    mat mul(mat A, mat B) {
        int n = A.size();
        mat res(n, vector<ll>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    res[i][j] = (res[i][j] + A[i][k]*B[k][j]) % MOD;
                }
            }
        }
        return res;
    }
     
    mat mexp(mat M, ll e) {
        if(e == 1)
            return M;
        if(e % 2)
            return mul(M, mexp(M, e - 1));
        mat R = mexp(M, e/2);
        return mul(R, R);
    }
     
    int main() {
        ll n, m;
        cin >> n >> m;
        if(m > n) {
            cout << 1 << endl;
            return 0;
        }
        mat M(m, vector<ll>(m));
        M[0][0] = M[0][m - 1] = 1;
        for(int i = 1; i < m; i++)
            M[i][i - 1] = 1;
        mat R = mexp(M, n - m + 1);
        //for(int i = 0; i < m; i++) {
        //    for(int j = 0; j < m; j++)
        //        cout << R[i][j] << " ";
        //    cout << endl;
        //}
        ll res = 0;
        for(int i = 0; i < m; i++)
            res = (res + R[0][i])%MOD;
        cout << res << endl;
    }