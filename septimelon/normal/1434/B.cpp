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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-7;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> vals;
    vector<pair<int, int>> gre;
    for (int i = 0; i < 2 * n; ++i) {
        char c;
        cin >> c;
        if (c == '+') {
            gre.push_back({ 0, vals.size() });
            vals.push_back(0);
            continue;
        }
        int cn;
        cin >> cn;
        if (gre.size() == 0 || gre.back().first >= cn) {
            cout << "NO\n";
            return 0;
        }
        vals[gre.back().second] = cn;
        gre.pop_back();
        if (gre.size() > 0) {
            gre.back().first = max(gre.back().first, cn);
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << vals[i] << " ";
    }

    return 0;
}