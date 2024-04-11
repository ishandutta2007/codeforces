#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
const int A = 1e6 + 13;
const int N = 2000 + 13;
//const int N = 10;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(2);

int sum(int a, int b) {
    a += b;
    return (a < M ? a : a - M);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

int f[N], invf[N];

int C(int n, int k) {
    return mul(f[n], mul(invf[n - k], invf[k]));
}

int inv[N];
int res[N][N];
int c[N];
//int res[N];


void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int odd = (m + 1) / 2;

    c[0] = 1;
    for(int j = 1; j <= min(n, k); j++) {
        c[j] = mul(c[j - 1], mul(n - j + 1, inv[j]));
//        cout << "c " << j << ' ' << c[j] <<  ' ' << n - j << ' ' << inv[j] << endl;
    }

    int ans = 0;
    int cur = pow2(m, n);
    int invm = pow2(m, M - 2);
    for(int j = 1; j <= min(n, k); j++) {
//        res[j] = mul(pow2(j, k - j + 1), pow2(j - 1, j - 1));
//        res[j] = pow2(j - 1, j);
//        if(j % 2 == 0)
//            res[j] = dif(res[j], 1);
//        else
//            res[j] = sum(res[j], 1);
////
//        res[j] = mul(res[j], pow2(j, k - j));
//        for(int l = j - 1; l >= 1; l--) {
//            res[j] = dif(res[j], mul(C(j, l), res[l]));
//        }

//        cout << "res " << j << ' ' << res[k][j] << endl;
//        res[j] = C(k - 1, j - 1);
        cur = mul(cur, mul(odd, invm));
//        ans = sum(ans, mul(res[k][j], mul(C(n, j), cur)));
//        ans = sum(ans, mul(res[k][j], mul(C(n, j), cur)));
        ans = sum(ans, mul(res[k][j], mul(c[j], cur)));
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < N; i++)
        inv[i] = pow2(i, M - 2);

    f[0] = invf[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = mul(f[i - 1], i);
        invf[i] = pow2(f[i], M - 2);
    }

    res[0][0] = 1;
    for(int k = 1; k < N; k++) {

        for(int j = 1; j <= k; j++) {
    //        p[j] = pow2(j, k);
//            res[k][j] = sum(res[k - 1][j - 1], mul(res[k - 1][j], j));
            res[k][j] =  mul(sum(res[k - 1][j - 1],res[k - 1][j]), j);
//            cout << res[k][j] << ' ';
//            res[k][j] = sum(res[k - 1][j - 1], mul(res[k - 1][j], k - 1));
//            for(int l = j - 1; l >= 1; l--) {
//                res[k][j] = dif(res[k][j], mul(C(j, l), res[k][l]));
//            }

        }
//        cout << endl;
    }

//    for(int k = 1; k < N; k++) {
//
//        for(int j = 1; j <= k; j++) {
//    //        p[j] = pow2(j, k);
//            res[k][j] = pow2(j, k);
//
//            //res[k][j] = sum(res[k - 1][j - 1], mul(res[k - 1][j], k - 1));
//            for(int l = j - 1; l >= 1; l--) {
//                res[k][j] = dif(res[k][j], mul(C(j, l), res[k][l]));
//            }
//            cout << res[k][j] << ' ';
//
//        }
//        cout << endl;
//    }



//    for(int i = 1; i < 10; i++) {
//        for(int j = 0; j <= i; j++)
//            cout << C(i, j) << ' ';
//        cout << endl;
//    }

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}