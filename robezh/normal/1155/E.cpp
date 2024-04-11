#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e6 + 3, N = mod + 2;

ll inv[N];

void calc_inv() {
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct matrix {
    static const int maxn = 55;
    int n, m;
    ll mat[maxn][maxn];
    ll a[maxn];
    ll res[maxn];
    matrix() { memset(mat, 0, sizeof(mat)); }
    void print() {
        cout << "MATRIX " << n << " " << m << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << mat[i][j] << "\t";
            }
            cout << "= " << res[i];
            cout << endl;
        }
    }
    void gauss() {
        for (int i = 0; i < n; i++) {
            int sid = -1;
            for (int j = i; j < n; j++)
                if (mat[j][i] > 0) {
                    sid = j;
                    break;
                }
            if (sid == -1) continue;
            if (sid != i) {
                for (int j = 0; j < n; j++) {
                    swap(mat[sid][j], mat[i][j]);
                    swap(res[sid], res[i]);
                }
            }
            for (int j = i + 1; j < n; j++) {
                ll ratio = mat[j][i] * inv[mat[i][i]] % mod;

                for (int k = 0; k < n; k++) {
                    mat[j][k] -= mat[i][k] * ratio % mod;
                    mat[j][k] += mod;
                    if(mat[j][k] >= mod) mat[j][k] -= mod;

                }
                res[j] += mod;
                res[j] -= res[i] * ratio % mod;
                if(res[j] >= mod) res[j] -= mod;

            }

        }
        for(int i = m - 1; i >= 0; i--) {
            ll sum = res[i];
            for(int j = i + 1; j < m; j++) {
                sum -= a[j] * mat[i][j] % mod;
                sum %= mod;
            }
            sum = (sum + mod) % mod;
            a[i] = sum * inv[mat[i][i]] % mod;
        }
    }
} mat;

int main() {
    calc_inv();
    set<int> S;
    mat.n = 50, mat.m =11;
    while(S.size() < mat.n) {
        int cur = rng() % mod;
        if(S.find(cur) == S.end()) S.insert(cur);
    }
    int i = 0;
    for(int x : S) {
        cout << "? " << x << endl;
        fflush(stdout);
        ll pw = 1;
        for(int j = 0; j < mat.m; j++) {
            mat.mat[i][j] = pw;
            pw *= x;
            pw %= mod;
        }
        cin >> mat.res[i++];
    }
//    mat.print();

    mat.gauss();
//    mat.print();
    for(i = mat.m; i < mat.n; i++) {
        if(mat.res[i] != 0) {
            cout << "! -1" << endl;
            fflush(stdout);
            return 0;
        }
    }
    for(ll x = 0; x < mod; x++) {
        ll sum = 0, pw = 1;
        for(int j = 0; j < mat.m; j++) {
            sum += mat.a[j] * pw % mod;
            pw *= x;
            pw %= mod;
        }

        if(sum % mod == 0) {
            cout << "! " << x << endl;
            fflush(stdout);
            return 0;
        }
    }
    cout << "! " << -1 << endl;
    fflush(stdout);
    return 0;

}