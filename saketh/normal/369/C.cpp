#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 100;

int N;
vector<pair<int, bool>> adj[MAXN];

bool got[MAXN];
bool blw[MAXN];

vector<int> ans;

bool check(int loc, int par, bool fix) {
    got[loc] = fix;

    for (auto p : adj[loc]) {
        if (p.first == par) continue;
        blw[loc] |= check(p.first, loc, p.second);
    }

    if (got[loc] && !blw[loc]) ans.push_back(loc);
    return got[loc] | blw[loc];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v, t;
        cin >> u >> v >> t;

        adj[u-1].emplace_back(v-1, t == 2);
        adj[v-1].emplace_back(u-1, t == 2);
    }

    check(0, 0, false);

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (int v : ans)
        cout << v + 1 << " ";
    cout << "\n";
}