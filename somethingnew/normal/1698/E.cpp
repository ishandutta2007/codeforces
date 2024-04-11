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
int mod = 998244353;
void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> aind(n);
    vector<int> a(n), b(n, -1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x--;
        a[x] = i;
        aind[i] = x;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x--;
        if (x >= 0) {
            b[x] = i;
        }
    }
    vector<int> prefmn(n);
    set<int> nex;
    for (int i = 0; i < n; ++i) {
        nex.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        nex.erase(b[i]);
    }
    prefmn[0] = (nex.find(a[0]) != nex.end());
    for (int i = 1; i < n; ++i) {
        prefmn[i] = prefmn[i - 1] + (nex.find(a[i]) != nex.end());
    }

    int res = 1;
    int t = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] == -1) {
            res *= prefmn[min(n - 1, i + s)] - t;
            res %= mod;
            t++;
        } else {
            if (i + s < aind[b[i]]) {
                res = 0;
            }
        }
    }
    cout << res << '\n';
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