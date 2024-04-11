#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 1e9 + 7;
//const int M = 998244353;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

void NO() {
    cout << "NO" << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l, r, ql, qr;
    cin >> n >> l >> r >> ql >> qr;

    int sum = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int ans = INF;
    int cur = 0;
    for(int lf = 0; lf <= n; lf++) {
        int rg = n - lf;
        ans = min(ans, sum * r + cur * l + max(0, rg - lf - 1) * qr + max(0, lf - rg - 1) * ql);

//        cout << lf << ' ' << rg << ' ' << cur << ' ' << sum << ' ' << sum * r << ' ' << cur * l << ' ' <<
//                sum * r + cur * l + max(0, rg - lf - 2) * qr + max(0, lf - rg - 2) * ql << endl;

        if(lf < n)
            cur += a[lf], sum -= a[lf];
    }

    cout << ans << endl;
}