#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    int totA = 0;
    vi a(N), leafs, non_leafs;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        totA += a[i];

        if (a[i] == 1) {
            leafs.push_back(i);
        } else {
            non_leafs.push_back(i);
        }
    }

    if (totA < 2 * (N - 1)) {
        cout << "NO\n";
        return 0;
    }

    int diam = non_leafs.size() - 1;

    vector<array<int, 2>> edges;
    auto add_edge = [&](int u, int v) {
        assert(--a[u] >= 0);
        assert(--a[v] >= 0);
        edges.push_back({ u, v });
        if (leafs.size() > 0 && leafs.back() == v)
            leafs.pop_back();
    };

    for (int i = 0; i + 1 < non_leafs.size(); i++) {
        add_edge(non_leafs[i], non_leafs[i+1]);
    }

    if (!leafs.empty()) {
        add_edge(non_leafs[0], leafs.back());
        diam++;
        if (!leafs.empty() && a[non_leafs.back()] > 0) {
            add_edge(non_leafs.back(), leafs.back());
            diam++;
        }
    }

    while (!leafs.empty()) {
        bool found = false;
        for (int i : non_leafs) {
            if (a[i]) {
                add_edge(i, leafs.back());
                found = true;
                break;
            }
        }
        assert(found);
    }

    cout << "YES " << diam << "\n";
    cout << edges.size() << "\n";
    for (auto [u, v] : edges) {
        cout << u + 1 << " " << v + 1 << "\n";
    }

    return 0;
}