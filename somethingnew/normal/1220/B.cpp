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
#define int long long
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> table(n, vector<int>(n));
    for (auto &i : table)
        for (auto &j : i)
            cin >> j;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n, k = (i + 2) % n;
        cout << (int)(sqrt(table[i][j] * table[i][k] / table[k][j]) + 1e-3) << ' ';
    }
}