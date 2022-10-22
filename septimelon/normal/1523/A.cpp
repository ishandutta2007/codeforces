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

bool isOneNeigh(int i, const string& s) {
    if (s[i] == '1') {
        return false;
    }
    int cn = 0;
    if (i > 0 && s[i - 1] == '1') {
        ++cn;
    }
    if (i < s.size() - 1 && s[i + 1] == '1') {
        ++cn;
    }
    return (cn == 1);
}

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<int> cand;
    for (int i = 0; i < n; ++i) {
        if (isOneNeigh(i, s)) {
            cand.push_back(i);
        }
    }
    for (int iter = 0; iter < m && !cand.empty(); ++iter) {
        vector<bool> all;
        for (int ci : cand) {
            if (s[ci] == '0') {
                s[ci] = '1';
                all.push_back(true);
            }
            else {
                all.push_back(false);
            }
        }
        vector<int> ncand;
        for (int i = 0; i < cand.size(); ++i) { 
            if (!all[i]) {
                continue;
            }
            int ci = cand[i];
            if (ci > 0 && isOneNeigh(ci - 1, s)) {
                ncand.push_back(ci - 1);
            }
            if (ci < n - 1 && isOneNeigh(ci + 1, s)) {
                ncand.push_back(ci + 1);
            }
        }
        cand = move(ncand);
    }

    cout << s << "\n";
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