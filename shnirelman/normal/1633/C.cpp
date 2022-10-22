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

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2500 + 13;
const int LOGN = 30;
const int K = 22;
const int M = 1e9 + 7;
const int A = 26;
const ld eps = 1e-15;

mt19937 rnd(45768);

/*
*/

void solve() {
    li hc, dc;
    cin >> hc >> dc;

    li hm, dm;
    cin >> hm >> dm;

    li k, w, a;
    cin >> k >> w >> a;

    for(int x = 0; x <= k; x++) {
        if((hm + dc + x * w - 1) / (dc + x * w) <= (hc + a * (k - x) + dm - 1) / dm) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}