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
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> av;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        av[a[i]]++;
    }
    vector<int> b;
    for (auto i : av) {
        for (int j = 0; j < min(i.second, 3ll); ++j) {
            b.push_back(i.first);
        }
    }
    if (b.size() > 20) {
        cout << "No\n";
        return;
    }
    for (int i = 0; i < b.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < j; ++k) {
                if (av[b[i] + b[j] + b[k]] == 0) {
                    cout << "No\n";
                    return;
                }
            }
        }
    }
    cout << "Yes\n";
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