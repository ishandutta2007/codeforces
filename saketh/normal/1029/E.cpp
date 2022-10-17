#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

array<int, 3> solve(vvi &adj, int loc, int par) {
    vector<array<int, 3>> ch;
    for (int nbr : adj[loc]) {
        if (nbr != par)
            ch.push_back(solve(adj, nbr, loc));
    }

    // in this case the node is already connected for free
    if (loc == 0 || par == 0) {
        int tot = 0;
        for (auto e : ch) {
            tot += min(e[0], min(e[1], e[2]));
        }
        return { INT_MAX, INT_MAX, tot };
    }

    // case where we don't connect this node or any of its children
    int v1 = 0;
    for (auto e : ch) {
        if (e[1] != INT_MAX) {
            v1 += e[1];
        } else {
            v1 = INT_MAX;
            break;
        }
    }

    // case where we don't connect this node, but at least one child is connected
    int v2 = 0;
    bool need_connect = true;
    priority_queue<int, vi, greater<int>> connect;
    for (auto e : ch) {
        if (e[1] == INT_MAX && e[2] == INT_MAX) {
            v2 = INT_MAX;
            break;
        }

        if (e[2] <= e[1]) {
            need_connect = false;
            v2 += e[2];
        } else {
            v2 += e[1];
            connect.push(e[2] - e[1]);
        }
    }

    if (v2 != INT_MAX && need_connect) {
        if (connect.empty()) v2 = INT_MAX;
        else v2 += connect.top();
    }

    // case where we connect in this node
    int v3 = 1;
    for (auto e : ch) {
        v3 += min(e[0], min(e[1], e[2]));
    }

    return { v1, v2, v3 };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    vvi adj(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    cout << solve(adj, 0, 0)[2] << "\n";

    return 0;
}