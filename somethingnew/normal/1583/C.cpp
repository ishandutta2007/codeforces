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
    int n, m;
    cin >> n >> m;
    vector<string> table(n);
    vector<int> bd(m);
    for (int i = 0; i < n; ++i) {
        cin >> table[i];
        if (i != 0) {
            for (int j = 1; j < m; ++j) {
                if (table[i-1][j] == 'X' and table[i][j - 1] == 'X')
                    bd[j] = 1;
            }
        }
    }
    for (int i = 1; i < m; ++i) {
        bd[i] = bd[i] + bd[i - 1];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;r--;
        if (bd[r] - bd[l] == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    //cin >> n;
    for (int i = 0; i < 1; ++i) {
        solve();
    }
}