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
bool cmp(vector<int> &a, vector<int> &b) {
    return a.size() < b.size();
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<vector<int>> ind(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
        ind[a[i]].push_back(i);
    }
    sort(all(ind), cmp);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < ind[i].size(); ++j) {
            b[ind[i+1][j]] = a[ind[i][0]] + 1;
        }
    }
    int c = a[ind.back().back()] + 1;
    for (int i = 0; i < n; ++i) {
        if (b[i] == 0)
            b[i] = c;
        cout << b[i] << ' ';
     }
    cout << '\n';
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