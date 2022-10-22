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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> x(m + 1), y(m + 1);
    vector<pair<int, int>> px(m + 1, { 0, 0 }), py(m + 1, { 0, 0 });
    vector<ll> mind(m + 1, INFL);
    int fx, fy;
    cin >> x[0] >> y[0] >> fx >> fy;
    for (int i = 0; i < m; ++i) {
        cin >> x[i + 1] >> y[i + 1];
    }
    for (int i = 0; i < m + 1; ++i) {
        px[i] = { x[i], i };
        py[i] = { y[i], i };
    }
    sort(px.begin(), px.end());
    sort(py.begin(), py.end());

    vector<vector<int>> r(m + 1);
    for (int i = 0; i < m; ++i) {
        r[px[i].second].push_back(px[i + 1].second);
        r[py[i].second].push_back(py[i + 1].second);
        r[px[i + 1].second].push_back(px[i].second);
        r[py[i + 1].second].push_back(py[i].second);
    }

    priority_queue<pair<int, int>> ana;
    ana.push({ INF, 0 });
    while (!ana.empty()) {
        if (mind[ana.top().second] <= INF - ana.top().first) {
            ana.pop();
            continue;
        }

        int ct = INF - ana.top().first, cv = ana.top().second;
        mind[cv] = ct;
        for (int i = 0; i < r[cv].size(); ++i) {
            ana.push({ INF - (ct + abs(x[cv] - x[r[cv][i]])), r[cv][i] });
            ana.push({ INF - (ct + abs(y[cv] - y[r[cv][i]])), r[cv][i] });
        }
    }

    ll ans = INFL;
    for (int i = 0; i < m + 1; ++i) {
        //cout << mind[i] << " ";
        ans = min(ans, mind[i] + abs(fx - x[i]) + abs(fy - y[i]));
    }

    cout << ans << "\n";

    return 0;
}