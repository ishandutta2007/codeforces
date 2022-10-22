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
const ld MEPS = EPS * 1e2;
const ll INFL = 1e18;
const int INF = 1e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    vector<int> per(n);
    for (int i = 0; i < n; ++i) {
        cin >> per[i];
    }

    for (int i = 0; i < n; ++i) {
        int cx = i, cy = i;
        int col = per[i];
        while (per[i] > 0) {
            if (ans[cx][cy] != 0) {
                cout << "-1\n";
                return 0;
            }
            ans[cx][cy] = col;
            --per[i];
            if (cy > 0 && ans[cx][cy - 1] == 0) {
                --cy;
            }
            else if (cx < n - 1 && ans[cx + 1][cy] == 0) {
                ++cx;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}