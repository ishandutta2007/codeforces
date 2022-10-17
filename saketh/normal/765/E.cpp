#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

    vi deg(N);
    for (int i = 0; i < N; i++) {
        deg[i] = adj[i].size();
    }

    queue<int> leafs;
    for (int i = 0; i < N; i++) {
        if (deg[i] <= 1)
            leafs.push(i);
    }

    vi weight(N, 1);
    vector<unordered_map<int, int>> chains(N);
    int fin = -1;

    while (!leafs.empty()) {
        int loc = leafs.front();
        leafs.pop();
        
        TRACE(cout << "PROC leaf " << loc + 1 << endl;)

        if (deg[loc] == 0) {
            fin = weight[loc];
            break;
        }

        if (chains[loc].size()) {
            fin = weight[loc] + chains[loc].begin()->first;
            WATCH(fin);
            break;
        }

        // i have one neighbor left
        int nbr;
        for (int cand : adj[loc])
            if (weight[cand])
                nbr = cand;

        // if that neighbor already has a chain like me, just delete myself
        if (chains[nbr].count(weight[loc]) && chains[nbr][weight[loc]] != loc) {
            TRACE(cout << "Deleting this chain of length " << weight[loc] << endl;)
            weight[loc] = 0;
            --deg[nbr];

            if (deg[nbr] <= 1)
                leafs.push(nbr);
            else if (deg[nbr] == 2 && chains[nbr].size())
                leafs.push(chains[nbr].begin()->second);
            continue;
        }

        // cannot contract into neighbor
        if (deg[nbr] > 2) {
            TRACE(cout << "Attaching a chain of length " << weight[loc] << " to " << nbr+1 << endl;)
            chains[nbr][weight[loc]] = loc;
            continue;
        }

        // ok, I can contract into the neighbor
        TRACE(cout << "Contracting into " << nbr+1 << endl;)
        if (chains[nbr].count(weight[loc]) && chains[nbr][weight[loc]] == loc)
            chains[nbr].erase(weight[loc]);
        weight[nbr] += weight[loc];
        TRACE(cout << "neighbor weight is now " << weight[nbr] << endl;)
        weight[loc] = 0;
        --deg[nbr];
        leafs.push(nbr);
    }

    if (fin == -1) {
        cout << -1 << endl;
        return 0;
    }

    fin--;
    while (fin % 2 == 0)
        fin /= 2;
    cout << fin << endl;
    return 0;
}