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
bool sosed(pair<int, int> a, pair<int, int> b) {
    return a.first == b.first or a.second == b.second;
}
void solve() {
    int n;
    cin >> n;
    set<pair<int, int>> bd = {{1, 1}, {1, n}, {n, 1}, {n, n}};
    vector<pair<int, int>> crd(3);
    vector<int> cnt(3);
    for (int i = 0; i < crd.size(); ++i) {
        cin >> crd[i].first >> crd[i].second;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            if (sosed(crd[i], crd[j])) {
                cnt[i]++;cnt[j]++;
            }
        }
    }
    pair<int, int> clet;
    for (int i = 0; i < 3; ++i) {
        if (cnt[i] == 2)
            clet = crd[i];
    }
    pair<int, int> trg;
    cin >> trg.first >> trg.second;
    if (bd.find(clet) != bd.end()) {
        if (clet.first == trg.first or clet.second == trg.second) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    if (abs(trg.first - clet.first) % 2 == 1 and abs(trg.second - clet.second) % 2 == 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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