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

// check if the whole subtree has the given expected color
bool ok(int loc, int par, int exp, vvi &adj, vi &color) {
    if (color[loc] != exp) return false;
    for (int nbr : adj[loc])
        if (nbr != par)
            if (!ok(nbr, loc, exp, adj, color))
                return false;
    return true;
}

// check if the given root works
bool ok(int root, vvi &adj, vi &color) {
    for (int nbr : adj[root])
        if (!ok(nbr, root, color[nbr], adj, color))
            return false;
    return true;
}

void flood(int loc, int par, vvi &adj, vi &color, vb &comp) {
    if (color[loc] != color[par]) return;
    comp[loc] = true;
    for (int nbr : adj[loc])
        if (nbr != par)
            flood(nbr, loc, adj, color, comp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vvi adj(N);
    for (int e = 0; e < N - 1; e++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vi color(N);
    for (int i = 0; i < N; i++)
        cin >> color[i];

    // connected component of vertex 0
    vb comp(N);
    flood(0, 0, adj, color, comp);

    bool all = true;
    for (int v = 0; v < N; v++) {
        if (!comp[v]) {
            all = false;
            continue;
        }

        vi ext;
        for (int nbr : adj[v])
            if (!comp[nbr])
                ext.push_back(nbr);

        if (ext.size() == 0) continue;

        if (ok(v, adj, color)) {
            cout << "YES\n" << v + 1 << endl;
        } else if (ext.size() == 1 && ok(ext[0], adj, color)) {
            cout << "YES\n" << ext[0] + 1 << endl;
        } else cout << "NO" << endl;
        return 0;
    }

    if (all) cout << "YES\n1" << endl;
    else cout << "NO" << endl;
    return 0;
}