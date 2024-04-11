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
bool slv(vector<int> a, int n, int m) {
    int c = 0;
    int cndlone = 0;
    for (int i = 0; i < a.size(); ++i) {
        a[i] /= n;
        if (a[i] >= 2)
        c += a[i];
        if (a[i] >= 3)
            cndlone = 1;
    }
    if (m <= c and m % 2 == c % 2)
        return 1;
    return (m <= c and cndlone);
}
void solve() {
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    if (slv(a, n, m) or slv(a, m, n))
        cout << "YES\n";
    else
        cout << "NO\n";
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