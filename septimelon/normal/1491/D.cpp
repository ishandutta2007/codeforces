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
const int INF = 1e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

vector<int> inds(int x) {
    vector<int> ans;
    for (int i = 0; i < 32; ++i) {
        if (x & 1) {
            ans.push_back(i);
        }
        x = (x >> 1);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve() {
    int u, v;
    cin >> u >> v;
    vector<int> vu = inds(u), vv = inds(v);
    vv.push_back(-1);
    reverse(vu.begin(), vu.end());
    reverse(vv.begin(), vv.end());

    bool elim = false;
    while (vu.size() > 0) {
        //cout << vu.back() << " " << vv.back() << "\n";
        if (vu.back() > vv.back()) {
            if (elim) {
                vu.pop_back();
            }
            else {
                break;
            }
        }
        else if (vu.back() == vv.back()) {
            if (vu.size() < vv.size() || !elim) {
                elim = false;
                vv.pop_back();
                vu.pop_back();
            }
            else {
                vu.pop_back();
            }
        }
        else {
            elim = true;
            vv.pop_back();
            vu.pop_back();
        }
    }

    if (vu.size() > 0 || vv.size() > 1) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}