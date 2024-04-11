#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> table(n, vector<int>(n));
    for (auto &i : a)
        cin >> i;
    for (int i = 0; i < n; ++i) {
        int x = i, y = i, t = a[i];
        table[x][y] = a[i];
        t--;
        while (t != 0) {
            if (y != 0 and table[x][y-1] == 0) {
                y--;
            } else if (x + 1 != n and table[x + 1][y] == 0) {
                x++;
            } else {
                cout << -1;
                return;
            }
            table[x][y] = a[i];
            t--;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= j)
                cout << table[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n = 1;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}