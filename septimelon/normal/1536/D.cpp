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

bool LookAtLinkedArray(int inserted, int& cur_ind, vector<int>& val, vector<int>& prev, vector<int>& next) {
    if (next[cur_ind] != -1 && val[next[cur_ind]] == inserted) {
        cur_ind = next[cur_ind];
    }
    if (prev[cur_ind] != -1 && val[prev[cur_ind]] == inserted) {
        cur_ind = prev[cur_ind];
    }
    if (val[cur_ind] > inserted && val[prev[cur_ind]] < inserted) {
        cur_ind = prev[cur_ind];
    }

    if (val[cur_ind] == inserted) {
        return true;
    }

    if (val[cur_ind] >= inserted || val[next[cur_ind]] <= inserted) {
        return false;
    }

    val.push_back(inserted);
    prev.push_back(cur_ind);
    next.push_back(next[cur_ind]);
    prev[next.back()] = val.size() - 1;
    next[prev.back()] = val.size() - 1;
    cur_ind = val.size() - 1;

    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> val{ -INF, INF }, prev{ -1, 0 }, next{ 1, -1 };
    int cur_ind = 0;
    for (int i = 0; i < n; ++i) {
        if (!LookAtLinkedArray(b[i], cur_ind, val, prev, next)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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