#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
//const int M = 998244353;
const int M = 1e9 + 7;
const int g = 3;
const int ALF = (1 << 20) - 3;
const int N = 2e5 + 13;
//const int N = 20 + 13;
const int K = 2e5 + 13;
//const int K = 20 + 13;
const int LOGN = 23;
const ld PI = acos(-1);
const ld eps = 1e-4;
const int S = 1007;
//const int B = 100;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
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

int f[N], inv[N];

int C(int n, int k) {
    return mul(f[n], mul(inv[k], inv[n - k]));
}
//
//void solve() {
//
//}

//map<pii, int> mem;
//
//int calc(int n, int k) {
//    if(n == 0 || k == 0)
//        return 0;
//
//    if(mem.count(pii(n, k)))
//        return mem[pii(n, k)];
//
//    int res = (1 << n) - 1;
//    for(int x = 0; x < k; x++)
//        res = min(res, max(calc(n - 1, x) * 2, calc(n - 1, k - x - 1) * 2 + 1));
//    return mem[pii(n, k)] = res;
//
////    if(k % 2 == 1) {
////        int res = calc(n - 1, k / 2) * 2 + 1;
////        return mem[pii(n, k)] = res;
////    } else {
////        int rs1 = calc(n - 1, k / 2 - 1) * 2;
////        int rs2 = calc(n - 1, k / 2) * 2 + 1;
////        return mem[pii(n, k)] = max(rs1, rs2);
////    }
//}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//    for(int n = 1; n < 5; n++) {
//        for(int k = 0; k < (1 << n); k++) {
//            cout << n << ' ' << k << ' ' << calc(n, k) << endl;
//        }
//    }

    int n, k;
    cin >> n >> k;

    if(k >= n) {
        cout << pow2(2, n) << endl;
        return 0;
    }

    f[0] = inv[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = mul(f[i - 1], i);
        inv[i] = pow2(f[i], M - 2);
    }

    int ans = 0;
    for(int i = 0; i <= k; i++) {
        ans = sum(ans, C(n, i));
    }

    cout << ans << endl;

//    cout << sum(pow2(2, k), 1) << endl;

//    cout << sum(calc(n, k), 1) << endl;

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}