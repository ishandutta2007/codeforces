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
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

//    if(a[n - 2] > a[n - 1]) {
//        cout << -1 << '\n';
//        return;
//    }

//    cout << n - 2 << '\n';
//    for(int i = 0; i < n - 2; i++) {
//        cout << i + 1 << ' ' <<
//    }

    for(int i = n - 2; i >= 0; i--) {
        if(a[i] > a[i + 1]) {
            cout << -1 << '\n';
            return;
        }

        if(a[i] >= a[i] - a[n - 1]) {
            cout << i << '\n';
            for(int j = 0; j < i; j++) {
                cout << j + 1 << ' ' << i + 1 << ' ' << n << '\n';
            }
            return;
        }
    }

    cout << 0 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}