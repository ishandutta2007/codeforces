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
const int INF = 1e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> cha, chb;

vector<int> en, ou;

int eulerDfs(int cv, int ct) {
    en[cv] = ct;
    ++ct;
    for (int ch : chb[cv]) {
        ct = eulerDfs(ch, ct) + 1;
    }
    ou[cv] = ct;
    return ct;
}

int maxSetDfs(int cv, set<pair<int, int>>& cli) {
    pair<int, int> cp{ en[cv], ou[cv] }, remp{ -1, -1 };
    auto nex = cli.upper_bound(cp);
    if (nex != cli.end() && nex->second <= cp.second) {
        cp = { -1, -1 };
    }
    else if (nex != cli.begin()) {
        --nex;
        if (nex->second >= cp.first) {
            remp = *nex;
            cli.erase(nex);
        }
    }
    if (cp.first != -1) {
        cli.insert(cp);
    }

    int max_set_size = cli.size();
    for (int ch : cha[cv]) {
        max_set_size = max(max_set_size, maxSetDfs(ch, cli));
    }

    if (cp.first != -1) {
        cli.erase(cli.lower_bound(cp));
    }
    if (remp.first != -1) {
        cli.insert(remp);
    }

    return max_set_size;
}

void solve() {
    int n;
    cin >> n;
    cha.assign(n, {});
    chb.assign(n, {});
    for (int i = 1; i < n; ++i) {
        int ro;
        cin >> ro;
        --ro;
        cha[ro].push_back(i);
    }
    for (int i = 1; i < n; ++i) {
        int ro;
        cin >> ro;
        --ro;
        chb[ro].push_back(i);
    }

    en.resize(n);
    ou.resize(n);

    eulerDfs(0, 0);

    set<pair<int, int>> clset;

    cout << maxSetDfs(0, clset) << "\n";
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