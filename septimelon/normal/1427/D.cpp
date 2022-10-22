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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> opers;
    while (true) {
        map<int, int> alrs;
        for (int i = 0; i < n; ++i) {
            if (alrs.count(a[i] + 1) == 0) {
                alrs.insert({ a[i], i });
                continue;
            }
            int ls = i - 1;
            while (a[i] - a[ls] == i - ls) {
                --ls;
            }
            
            opers.push_back({});
            if (alrs[a[i] + 1] > 0) {
                opers.back().push_back(alrs[a[i] + 1]);
            }
            opers.back().push_back(ls + 1 - alrs[a[i] + 1]);
            opers.back().push_back(i - ls);
            if (i < n - 1) {
                opers.back().push_back(n - i - 1);
            }
            
            vector<int> b;
            for (int j = i + 1; j < n; ++j) {
                b.push_back(a[j]);
            }
            for (int j = ls + 1; j <= i; ++j) {
                b.push_back(a[j]);
            }
            for (int j = alrs[a[i] + 1]; j <= ls; ++j) {
                b.push_back(a[j]);
            }
            for (int j = 0; j < alrs[a[i] + 1]; ++j) {
                b.push_back(a[j]);
            }
            a = b;
            break;
        }
        if (alrs.size() == n) {
            break;
        }
    }

    cout << opers.size() << "\n";
    for (int i = 0; i < opers.size(); ++i) {
        cout << opers[i].size() << " ";
        for (int j = 0; j < opers[i].size(); ++j) {
            cout << opers[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}