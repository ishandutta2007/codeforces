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
const ld EPS = 1e-9;
const ll INFL = 2e18;
const int INF = 1e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);
const int WIDE = 100000;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;
    vector<int> open;
    for (int i = 0; i < n; ++i) {
        int ca;
        cin >> ca;
        if (ca == 1) {
            open.push_back(1);
        }
        else {
            while (open.back() != ca - 1) {
                open.pop_back();
            }
            ++open.back();
        }
        for (int i = 0; i < open.size() - 1; ++i) {
            cout << open[i] << ".";
        }
        cout << open.back() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    for (int t = 0; t < q; ++t) {
        solve();
    }

    return 0;
}