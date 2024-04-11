#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

void go(bool &fail, vector<vector<int>> &adj, vector<int> &col, int loc, int put) {
    if (col[loc] != 0) {
        if (col[loc] != put) fail = true;
        return;
    }

    col[loc] = put;

    for (int nbr : adj[loc]) {
        go(fail, adj, col, nbr, 3 - put);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<int> col(N);
    bool fail = false;

    for (int i = 0; i < N; i++) {
        if (col[i] != 0) continue;
        go(fail, adj, col, i, 1);
    }

    if (fail) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> a, b;

    for (int i = 0; i < N; i++) {
        if (col[i] == 1)
            a.push_back(i+1);
        else b.push_back(i+1);
    }

    cout << a.size() << "\n";
    for (int v : a)
        cout << v << " ";
    cout << "\n";

    cout << b.size() << "\n";
    for (int v : b)
        cout << v << " ";
    cout << "\n";

    return 0;
}