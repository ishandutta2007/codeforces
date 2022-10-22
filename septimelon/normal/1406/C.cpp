#include <algorithm>
#include <cmath>
#include <ctime>
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
typedef long double ld;

const ll INFL = 1e18;
const int INF = 1000000007;
const ld PI = acos(-1);
const ld EPS = 1e-13;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> r(n);
    vector<int> deg(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        r[u].push_back(v);
        r[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }

    vector<int> leaf(n, -1);
    vector<int> siz(n, 1);
    vector<bool> alr(n, false);
    priority_queue<pair<int, int>> que;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1) {
            que.push({ INF - siz[i], i });
        }
    }

    for (int it = 0; it < n; ++it) {
        int cv = que.top().second;
        que.pop();
        if (leaf[cv] == -1) {
            leaf[cv] = cv;
        }
        alr[cv] = true;
        for (int i = 0; i < r[cv].size(); ++i) {
            if (!alr[r[cv][i]]) {
                leaf[r[cv][i]] = leaf[cv];
                siz[r[cv][i]] += siz[cv];
                --deg[r[cv][i]];
                if (deg[r[cv][i]] == 1) {
                    que.push({ INF - siz[r[cv][i]], r[cv][i] });
                }
            }
        }
    }

    vector<pair<int, int>> si;
    for (int i = 0; i < n; ++i) {
        //cout << siz[i] << " ";
        si.push_back({ siz[i], i });
    }
    sort(si.begin(), si.end());
    
    if (n % 2 != 0 || si[n - 2].first != n / 2) {
        cout << si[n - 2].second + 1 << " " << si[n - 1].second + 1 << "\n";
        cout << si[n - 2].second + 1 << " " << si[n - 1].second + 1 << "\n";
    }
    else {
        cout << leaf[si[n - 2].second] + 1 << " " << r[leaf[si[n - 2].second]][0] + 1 << "\n";
        cout << leaf[si[n - 2].second] + 1 << " " << si[n - 1].second + 1 << "\n";
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