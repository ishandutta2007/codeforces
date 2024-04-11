#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 100;

int N;
vector<pair<int, int>> adj[MAXN];

double ans[MAXN];
int size[MAXN];
int travel[MAXN];

void solve(int loc, int par) {
    size[loc] = 1;

    vector<pair<double, int>> order;

    for (auto e : adj[loc]) {
        int nbr = e.first;
        if (nbr == par) continue;

        solve(nbr, loc);

        size[loc] += size[nbr];

        travel[nbr] += 2 * e.second;
        ans[nbr] += e.second;

        travel[loc] += travel[nbr];

        order.emplace_back(double(travel[nbr]) / size[nbr], nbr);
    }

    sort(order.begin(), order.end());

    int bef = 0;
    for (auto p : order) {
        int nbr = p.second;
        double chance = size[nbr] / double(size[loc]);

        ans[loc] += chance * (bef + ans[nbr]);
        bef += travel[nbr];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 1; i < N; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        adj[u-1].emplace_back(v-1, c);
        adj[v-1].emplace_back(u-1, c);
    }

    solve(0, 0);

    cout << ans[0] * N / (N - 1) << "\n";
}