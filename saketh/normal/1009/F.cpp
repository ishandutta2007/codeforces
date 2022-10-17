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

const int MAXN = 1e6;

int ans[MAXN];
vi dep[MAXN];
int out[MAXN];

void solve(vvi &adj, int loc, int par) {
    int ms = -1;

    for (int nbr : adj[loc]) {
        if (nbr == par) continue;
        solve(adj, nbr, loc);
        if (ms == -1 || dep[nbr].size() > dep[ms].size())
            ms = nbr;
    }

    if (ms == -1) {
        ans[loc] = 0;
        dep[loc] = { 1 };
        return;
    }

    ans[loc] = ans[ms];
    swap(dep[loc], dep[ms]);
    dep[loc].push_back(1);
    if (dep[loc][ans[loc]] == 1)
        ans[loc] = dep[loc].size() - 1;

    for (int nbr : adj[loc]) {
        if (nbr == par) continue;
        if (nbr == ms) continue;

        for (int i = 0; i < dep[nbr].size(); i++) {
            int dist = dep[nbr].size() - i;
            int inx = dep[loc].size() - 1 - dist;
            dep[loc][inx] += dep[nbr][i];

            if (dep[loc][inx] == dep[loc][ans[loc]]) {
                ans[loc] = max(ans[loc], inx);
            } else if (dep[loc][inx] > dep[loc][ans[loc]]) {
                ans[loc] = inx;
            }
        }
    }

    out[loc] = dep[loc].size() - 1 - ans[loc];
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

    solve(adj, 0, 0);
    for (int i = 0; i < N; i++)
        cout << out[i] << "\n";

    return 0;
}