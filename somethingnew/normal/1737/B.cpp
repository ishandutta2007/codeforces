//        
//   @roadfromroi 
//        
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
int getr(int r) {
    if (r == 0)
        return 0;
    int val = 0;
    int ll = 0, rr = sqrt(r) + 3;
    while (ll + 1 < rr) {
        int m = ll + rr >> 1;
        if (m * m > r) {
            rr = m;
        } else {
            ll = m;
        }
    }
    val += ll;
    ll = 0, rr = sqrt(r) + 3;
    while (ll + 1 < rr) {
        int m = ll + rr >> 1;
        if (m * (m + 1) > r) {
            rr = m;
        } else {
            ll = m;
        }
    }
    val += ll;
    ll = 0, rr = sqrt(r) + 3;
    while (ll + 1 < rr) {
        int m = ll + rr >> 1;
        if (m * (m + 2) > r) {
            rr = m;
        } else {
            ll = m;
        }
    }
    val += ll;
    return val;
}
void solve() {
    int l, r;
    cin >> l >> r;
    cout << getr(r) - getr(l-1) << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}