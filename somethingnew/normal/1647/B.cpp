#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "climits"
#include "queue"
#include "array"
#include "numeric"
#include "random"
using namespace std;
#define all(x) x.begin(), x.end()
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> pole(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c == '1')
                pole[i][j] = 1;
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            int res = pole[i][j] + pole[i+1][j] + pole[i][j+1] +pole[i+1][j+1];
            if (res == 3) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}