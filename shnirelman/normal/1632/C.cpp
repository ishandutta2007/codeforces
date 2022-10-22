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
const int N = 3e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

void solve() {
    int a, b;
    cin >> a >> b;

    int ans = b - a;

    for(int i = b; i < b + b - a; i++) {
        int res = 1 + i - b;
//        int a1 = a;
//        for(int k = 0; k <= 22; k++) {
            for(int j = 22; j >= 0; j--) {
                if(((1 << j) & a) && !((1 << j) & i)) {
                    res += (1 << j) - (a & ((1 << j) - 1));
                    int a1 = a + (1 << j) - (a & ((1 << j) - 1));
                    for(int k = j; k <= 22; k++) {
                        if(((1 << k) & a1) && !((1 << k) & i)) {
                            res += (1 << k) - (a1 & ((1 << k) - 1));
                            a1 += (1 << k) - (a1 & ((1 << k) - 1));
                        }
                    }
                    break;
                }
            }
//        }


//        cout << i << ' ' << res << endl;

        ans = min(ans, res);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}