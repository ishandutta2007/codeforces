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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e11;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> lens;
    int cl = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[cl]) {
            lens.push_back(i - cl);
            cl = i;
        }
    }
    lens.push_back(n - cl);

    int ans = 0, ci = 0, cj = 0;
    while (ci < lens.size()) {
        while (cj < ci || (cj < lens.size() && lens[cj] == 1)) {
            ++cj;
        }
        if (cj < lens.size()) {
            --lens[cj];
        }
        else {
            lens.pop_back();
        }
        ++ci;
        ++ans;
    }

    cout << ans << "\n";
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