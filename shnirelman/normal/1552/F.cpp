//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 998244353;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

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

/*
1
10 6
14 6
2 20
9 10
13 18
15 12
11 7

*/

int a[N], b[N], s[N];
int res[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
//
//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();

    int n;
    cin >> n;

    vector<pii> p;
    for(int i = 0; i < n; i++) {
        cin >> b[i] >> a[i] >> s[i];
        p.emplace_back(b[i], i);
        p.emplace_back(a[i], i + n);
    }

    sort(p.rbegin(), p.rend());

    int r2 = pow2(2, M - 2);

    int cur = 0;
    int ans = (b[n - 1] + 1) % M;
//    bool odd = false;
    for(int i = 0; i < p.size(); i++) {
        if(p[i].s < n) {
            int ind = p[i].s;

            res[ind] = sum(s[ind], cur);
            cur = sum(cur, res[ind]);

//            if(odd) {
//                res[i] =
//            }
            ans = sum(ans, mul(b[ind] - a[ind], res[ind]));
        } else {
            int ind = p[i].s - n;

            cur = dif(cur, res[ind]);
        }
    }

    cout << ans << endl;
}