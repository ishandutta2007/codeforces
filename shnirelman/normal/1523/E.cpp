#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<li, li>;

const int INF = 1e9 + 14;
const int M = 1e9 + 7;//998244353;
const int N = 1e5 + 13;

/*
1
3 2
101
*/

int sum(int a, int b) {
    a += b;
    if(a >= M)
        a -= M;
    return a;
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
    if(k & 1)
        return mul(pw, mul(pw, n));
    else
        return mul(pw, pw);
}

int p[N], r[N];
int inv[N];

int C(int n, int k) {
    if(k > n)
        return 0;
    return mul(p[n], mul(r[k], r[n - k]));
}

int rC(int n, int k) {
    return mul(r[n], mul(p[k], p[n - k]));
}

void solve() {
    int n, k;
    cin >> n >> k;

    int ans =0 ;

    vector<int> pr(n + 1, 0);
    for(int m = 0; k * 1ll * (m - 1) + 1 <= n; m++) {
//        pr[i] = mul(C(n - (k - 1) * i, i), rC(n, i));//pow2(C(n, i), M - 2))
//        cout << i << ' ' << pr[i] << ' ' << C(n - (k - 1) * i, i) << ' ' << C(n, i) << endl;

//        pr[m] = mul(C(n - (k - 1) * m, m), rC(n, m));
        pr[m] = mul(C(n - (k - 1) * m, m), rC(n, m));
        if(m > 0) for(int i = n - k + 1; i < n; i++) if(i >= m - 1) {
//            pr[m] = sum(pr[m], mul(inv[n], mul(C(i - (k - 1) * (m - 1), m - 1), rC(i, m - 1))));
            pr[m] = sum(pr[m], mul(mul(C(i, m - 1), rC(n, m)), mul(C(i - (k - 1) * (m - 1), m - 1), rC(i, m - 1))));
//            cout << "for " << m << ' ' << i << ' ' << inv[n] << ' ' <<
//                C(i - (k - 1) * (m - 1), m - 1) << ' ' << C(i, m - 1) << endl;
        }

//        cout << m << ' ' << pr[m] << ' ' << C(n - (k - 1) * m, m) << ' ' << C(n, m) << endl;
    }

//    for(int i = 0; k * 1ll * i <= n; i++) {
//        pr[i] = mul(C(n - (k - 1) * i, i), rC(n, i));//pow2(C(n, i), M - 2))
////        cout << i << ' ' << pr[i] << ' ' << C(n - (k - 1) * i, i) << ' ' << C(n, i) << endl;
//
////        pr[m] = mul(C(n - (k - 1) * m, m), rC(n, m));
//
//    }

    for(int i = 1; i < n; i++) {
        ans = sum(ans, mul(dif(pr[i], pr[i + 1]), (i + 1)));
    }

    cout << ans << endl;
}

/*
1
3 2
*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    p[0] = 1;
    r[0] = 1;
//    inv[0] = 1;
    for(int i = 1; i < N; i++) {
        p[i] = mul(p[i - 1], i);
        r[i] = pow2(p[i], M - 2);
//        inv[i] = pow2(i, M - 2);
    }

    while(t--)
        solve();
}