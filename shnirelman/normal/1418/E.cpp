#include <bits/stdc++.h>

#define f first
#define s second
#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 998244353;//1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    return (a + b) % M;
//    a += b;
//    return (a >= M ? a - M : a);
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

    if(k % 2)
        return mul(pw, n);
    else
        return pw;
}
/*
*/

int d[N];
int p[N];

void solve() {
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        cin >> d[i];
//        d[i] %= M;
    }

    sort(d, d + n);

    p[0] = 0;
    for(int i = 0; i < n; i++) {
        p[i + 1] = sum(p[i], d[i]);
    }

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        int j = lower_bound(d, d + n, b) - d;

        int c1 = n - j;

        if(c1 < a) {
            cout << 0 << '\n';
            continue;
        }

        int res = mul(dif(p[n], p[j]), mul(c1 - a, pow2(c1, M - 2)));

        res = sum(res, mul(p[j], mul(c1 + 1 - a, pow2(c1 + 1, M - 2))));

        res %= M;
        while(res < 0)
            res += M;

        cout << res << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}