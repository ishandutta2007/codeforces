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
#define int long long
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> ex(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < n)
            ex[a[i]]++;
    }
    int k2 = k;
    int gr = 0;
    int ext = 0;
    for (int i = 0; i <= n; ++i) {
        gr = i;
        if (ex[i] == 0) {
            k2--;
        }
        if (k2 == -1)break;
    }
    if (gr == n) {
        cout << 0 << '\n';
        return;
    }
    map<int, int> exx;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= gr) {
            exx[a[i]]++;
        }
    }
    vector<int> nm;
    for (auto i : exx)
        nm.push_back(i.second);
    sort(all(nm));
    int res = exx.size();
    for (int i = 0; i < nm.size(); ++i) {
        if (nm[i] <= k) {
            res--;
            k -= nm[i];
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