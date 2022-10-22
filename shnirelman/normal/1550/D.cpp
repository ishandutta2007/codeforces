#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 200000 + 13;
const int M = 1e9 + 7;
const int B = 600;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
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

int p[N], r[N];

int C(int n, int k) {
    if(k > n)
        return 0;

    return mul(p[n], mul(r[k], r[n - k]));
}

/*
1
3 0 3
*/

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    int ans = 0;
    int mn = min(r - n, 1 - l);
//    int mn = max(1, 1 - l);

    int n1 = n / 2, n2 = n - n / 2;

    int cnt = max(0, mn);//abs(mx - mn) + 1);

    ans = mul(cnt, C(n, n1));
    if(n % 2 == 1)
        ans = sum(ans, mul(cnt, C(n, n2)));

//    cout << mn << ' ' << mx << ' ' << n1 << ' ' << n2 << ' ' << C(n, n1) << ' ' << cnt << endl;
//    cout << mn << ' ' << n1 << ' ' << n2 << ' ' << C(n, n1) << ' ' << cnt << endl;

    int lf = 1, rg = n;
    for(int i = mn + 1; i <= r; i++) {
        while(lf - i < l)
            lf++;
        while(rg + i > r)
            rg--;

//        cout << i << ' ' << lf << ' ' << rg << endl;
        if(rg < lf - 1)
            break;

//        cout << i << ' ' << lf << ' ' << rg << endl;

        if(n1 >= lf - 1 && n - rg <= n2 )
            ans = sum(ans, C(rg - lf + 1, n1 - lf + 1));
        if(n1 != n2 && n1 >= n - rg && n2 >= lf - 1)
            ans = sum(ans, C(rg - lf + 1, n2 - lf + 1));
    }

    cout << ans << '\n';
//    lf = 1, rg = n;
//    for(int i = mn - 1; i >= 1; i--) {
//        while(lf - i < l)
//            lf++;
//        while(rg + i > r)
//            rg--;
//        if(rg < lf)
//            break;
//
//        ans = sum(ans, C(rg - lf + 1, n1 - lf + 1));
//        if(n1 != n2)
//            ans = sum(ans, C(rg - lf + 1, n2 - lf + 1));
//    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    p[0] = 1, r[0] = 1;
    for(int i = 1; i < N; i++) {
        p[i] = mul(p[i - 1], i);
        r[i] = pow2(p[i], M - 2);
//        if(i < 100)
//        cout << i << ' ' << p[i] << ' ' << r[i] << endl;
    }

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}