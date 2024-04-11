#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
//const int M = 998244353;
const int N = 5e5 + 13;
const int LOGN = 30;

int sum(int a, int b) {
    a += b;
    return (a < M ? a : a - M);
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

int f[N], inv[N];

int C(int n, int k) {
    return mul(f[n], mul(inv[k], inv[n - k]));
}

int a[N];

/*
3
3 3 3
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    f[0] = inv[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = mul(f[i - 1], i);
        inv[i] = pow2(f[i], M - 2);
    }

    int n;
    cin >> n;

    n++;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = sum(ans, C(a[i] + i, i + 1));
//        int res = 0;
//        for(int j = 0; j < a[i]; j++) {
//            cout << C(i + j, j) << ' ';
//            res += C(i + j, j);
//        }
//        cout << " = " << C(a[i] + i, i + 1)  << ' ' << res << endl;
//        cout << endl;
    }

    cout << ans << endl;
//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}