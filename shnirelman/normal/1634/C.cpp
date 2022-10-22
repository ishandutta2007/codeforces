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
    int n, k;
    cin >> n >> k;

    if(n % 2 != 0 && k % 2 == 0 || (n * k / 2) % k != 0 || (n * k + 1) / 2 % k != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for(int i = 1, cur = 0; i <= n * k; i += 2, cur++) {
            cout << i << ' ';
            if(cur == k - 1) {
                cur = -1;
                cout << '\n';
            }
        }

        for(int i = 2, cur = 0; i <= n * k; i += 2, cur++) {
            cout << i << ' ';
            if(cur == k - 1) {
                cur = -1;
                cout << '\n';
            }
        }
    }

//    if(k == 1) {
//        cout << "YES\n";
//        for(int i = 1; i <= n; i++) {
//            cout << i << '\n';
//        }
//        return;
//    } else if(k == 2 && n % 2 == 0) {
//        cout << "YES\n";
//        for(int i = 1; i <= n * k; i += 4) {
//            cout << i << ' ' << i + 2 << '\n';
//        }
//        for(int i = 2; i <= n * k; i += 4) {
//            cout << i << ' ' << i + 2 << '\n';
//        }
//
//    } else {
//        cout << "NO\n";
//    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();


}