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

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e18;
const ll INF = 1e9 + 7;
const ld PI = acos(-1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> s(n, vector<char>(n));
    int cx = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> s[i][j];
            if (s[i][j] != '.') {
                ++cx;
            }
        }
    }

    bool good = false;
    for (int iterx = 0; iterx < 3; ++iterx) {
        for (int itery = 0; itery < 3; ++itery) {
            if (iterx == itery) {
                continue;
            }
            vector<vector<char>> ns = s;
            int cy = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = (i + iterx) % 3; j < n; j += 3) {
                    if (s[i][j] == 'O') {
                        ++cy;
                        ns[i][j] = 'X';
                    }
                }
                for (int j = (i + itery) % 3; j < n; j += 3) {
                    if (s[i][j] == 'X') {
                        ++cy;
                        ns[i][j] = 'O';
                    }
                }
            }
            if (cy * 3 <= cx) {
                s = ns;

                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        cout << s[i][j];
                    }
                    cout << "\n";
                }

                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}