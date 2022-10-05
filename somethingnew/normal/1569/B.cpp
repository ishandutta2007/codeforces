#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "climits"
#include "map"
#include "cassert"
typedef double ld;
typedef long long ll;
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> table(n, string(n, '='));
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        table[i][i] = 'X';
        if (s[i] == '2') {
            cnt++;
            int next = -1;
            for (int j = 1; j < n; ++j) {
                if (s[(i + j) % n] == '2') {
                    next = (i + j) % n;
                }
            }
            if (next == -1) {
                cout << "NO\n";
                return;
            }
            table[i][next] = '+';
            table[next][i] = '-';
        }
    }
    if (cnt == 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto i : table)
        cout << i << '\n';
}
signed main() {
    int n;
    cin >> n;
    while (n--)
        solve();
}