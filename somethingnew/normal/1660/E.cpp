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
#include "queue"
#define all(x) x.begin(), x.end()
using namespace std;
vector<vector<int>> vals;
int get(int n, vector<string> &pole, int i, int j) {
    if (vals[i][j] == -2) {
        return 0;
    }
    vals[i][j] = -2;
    int t = get(n, pole, (i + 1) % n, (j + 1) % n);
    vals[i][j] = (pole[i][j] == '1') + t;
    return vals[i][j];
}
void solve() {
    int n;
    cin >> n;
    vals.assign(n, vector<int>(n, -1));
    vector<string> pole(n);
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        cin >> pole[i];
        for (int j = 0; j < n; ++j) {
            if (pole[i][j] == '1')
                sm++;
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, get(n, pole, i, 0));
    }
    res = min(res, n);
    cout << (n - res) + (sm - res) << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
/*

 */