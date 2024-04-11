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
const int N = 1e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

void solve() {
    int n, k;
    cin >> n >> k;

    if(k == 0) {
        for(int i = 0; i < n / 2; i++) {
            cout << i << ' ' << n - 1 - i << '\n';
        }
    } else if(k != n - 1) {
        cout << k << ' ' << n - 1 << '\n';
        cout << 0 << ' ' << n - 1 - k << '\n';
        for(int i = 1; i < n / 2; i++) {
            if(i != k && n - 1 - k != i) {
                cout << i << ' ' << n - 1 - i << '\n';
            }
        }
    } else if(n == 4) {
        cout << -1 << '\n';
    } else {
        cout << n - 2 << ' ' << n - 1 << '\n';
        cout << 1 << ' ' << 3 << '\n';
        cout << 0 << ' ' << n - 4 << '\n';
        cout << 2 << ' ' << n - 3 << '\n';
        for(int i = 4; i < n / 2; i++) {
            cout << i << ' ' << n - 1 - i << '\n';
        }
//        cout << 2 << ' ' << n - 3 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}