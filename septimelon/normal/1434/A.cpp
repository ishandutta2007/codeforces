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

    vector<int> a(6);
    for (int i = 0; i < 6; ++i) {
        cin >> a[i];
    }
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<pair<int, int>> dist;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            dist.push_back({ b[i] - a[j], i });
        }
    }

    sort(dist.begin(), dist.end());

    int ans = INF;
    vector<int> val(n, 0);
    int dinc = 0;
    priority_queue<pair<int, int>> linc;
    for (int i = 0; i < 6 * n; ++i) {
        int cv = dist[i].first, ci = dist[i].second;
        if (val[ci] == 0) {
            ++dinc;
        }
        val[ci] = cv;
        linc.push({ INF - cv, ci });
        while (val[linc.top().second] != INF - linc.top().first) {
            linc.pop();
        }
        if (dinc == n) {
            ans = min(ans, cv - (INF - linc.top().first));
        }
    }

    cout << ans << "\n";

    return 0;
}