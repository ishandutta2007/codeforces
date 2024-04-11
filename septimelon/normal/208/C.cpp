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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> r(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        r[u].push_back(v);
        r[v].push_back(u);
    }

    vector<ld> dor(n, 0);
    dor[0] = 1;
    vector<int> step(n, INF);
    step[0] = 0;
    for (int it = 0; it < n; ++it) {
        for (int i = 0; i < n; ++i) {
            if (step[i] != it) {
                continue;
            }
            vector<int> to;
            for (int j = 0; j < r[i].size(); ++j) {
                if (step[r[i][j]] >= it + 1) {
                    to.push_back(r[i][j]);
                }
            }
            for (int j = 0; j < to.size(); ++j) {
                step[to[j]] = it + 1;
                dor[to[j]] += dor[i];
            }
        }
    }

    vector<ld> rdor(n, 0);
    rdor[n - 1] = 1;
    vector<int> rstep(n, INF);
    rstep[n - 1] = 0;
    for (int it = 0; it < n; ++it) {
        for (int i = 0; i < n; ++i) {
            if (rstep[i] != it) {
                continue;
            }
            vector<int> to;
            for (int j = 0; j < r[i].size(); ++j) {
                if (rstep[r[i][j]] >= it + 1) {
                    to.push_back(r[i][j]);
                }
            }
            for (int j = 0; j < to.size(); ++j) {
                rstep[to[j]] = it + 1;
                rdor[to[j]] += rdor[i];
            }
        }
    }

    ld mans = 1;
    for (int i = 1; i < n - 1; ++i) {
        if (step[i] + rstep[i] != step[n - 1]) {
            continue;
        }
        mans = max(mans, dor[i] * rdor[i] * 2 / dor[n - 1]);
    }

    cout << setprecision(9) << mans << "\n";

    return 0;
}