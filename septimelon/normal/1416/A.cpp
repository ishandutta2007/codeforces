#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
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

const int INF = 1000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;

void upd(int i, int v, map<int, int>& last, map<int, int>& mdist) {
    if (last.count(v) == 0) {
        last[v] = i;
        mdist[v] = i + 1;
    }
    else {
        mdist[v] = max(mdist[v], i - last[v]);
        last[v] = i;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> last, mdist;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        upd(i, a[i], last, mdist);
    }
    
    vector<pair<int, int>> dists;
    for (auto it = last.begin(); it != last.end(); ++it) {
        mdist[it->first] = max(mdist[it->first], n - it->second);
        dists.push_back({ mdist[it->first], it->first });
    }
    dists.push_back({ INF, INF });
    sort(dists.begin(), dists.end());

    int ci = 0;
    int minv = INF;
    for (int k = 1; k <= n; ++k) {
        while (dists[ci].first <= k) {
            minv = min(dists[ci].second, minv);
            ++ci;
        }
        if (minv == INF) {
            cout << "-1 ";
        }
        else {
            cout << minv << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }

    return 0;
}