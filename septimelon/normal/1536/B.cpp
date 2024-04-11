#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

//#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 998244353;
const ld EPS = 1e-11;
const ll INFL = 2e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int all = 'z' - 'a' + 1;
    vector<bool> sym(all, false);
    vector<vector<bool>> symp(all, vector<bool>(all, false));
    vector<vector<vector<bool>>> symt(5, vector<vector<bool>>(all, vector<bool>(all, false)));
    
    int n;
    string s;
    cin >> n >> s;
    
    vector<int> ind(n);
    for (int i = 0; i < n; ++i) {
        ind[i] = s[i] - 'a';
    }

    for (int i = 0; i < n; ++i) {
        sym[ind[i]] = true;
    }
    for (int i = 0; i < all; ++i) {
        if (!sym[i]) {
            cout << (char)('a' + i) << "\n";
            return;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        symp[ind[i]][ind[i + 1]] = true;
    }
    for (int i = 0; i < all; ++i) {
        for (int j = 0; j < all; ++j) {
            if (!symp[i][j]) {
                cout << (char)('a' + i) << (char)('a' + j) << "\n";
                return;
            }
        }
    }

    for (int i = 0; i < n - 2; ++i) {
        if (ind[i] < 5) {
            symt[ind[i]][ind[i + 1]][ind[i + 2]] = true;
        }
    }
    for (int i = 0; i < all; ++i) {
        for (int j = 0; j < all; ++j) {
            for (int k = 0; k < all; ++k) {
                if (!symt[i][j][k]) {
                    cout << (char)('a' + i) << (char)('a' + j) << (char)('a' + k) << "\n";
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}