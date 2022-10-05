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
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string res, a, b;
    cin >> a >> b;
    int cnt = 0;
    sort(all(a));
    sort(all(b));
    reverse(all(a));
    reverse(all(b));
    while (!a.empty() and !b.empty()) {
        if (cnt == k) {
            res.push_back(b.back());
            b.pop_back();
            cnt = -1;
        } else if (cnt == -k) {
            res.push_back(a.back());
            a.pop_back();
            cnt = 1;
        } else {
            if (a.back() < b.back() or (a.back() == b.back() and a.size() < b.size())) {
                res.push_back(a.back());
                a.pop_back();
                if (cnt > 0)
                    cnt++;
                else
                    cnt = 1;
            } else {
                res.push_back(b.back());
                b.pop_back();
                if (cnt < 0)
                    cnt--;
                else
                    cnt = -1;
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