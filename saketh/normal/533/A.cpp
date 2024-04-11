#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9;
const int MAXN = 5e5 + 500;

// returns # of unmatched caves, smallest height among them
// if mod is true, the unmatched miners are put into the miners vector
pair<int, int> match(vector<int> &miners, vector<int> &caves, bool mod) {
    sort(miners.begin(), miners.end());
    sort(caves.begin(), caves.end());

    int unm = 0;
    int low = INF;
    int nex = 0;

    priority_queue<int> avm;
    for (int c : caves) {
        while (nex < miners.size() && miners[nex] <= c) {
            avm.push(miners[nex]);
            nex++;
        }

        if (avm.size()) {
            avm.pop();
        } else {
            if (!unm) low = c;
            unm++;
        }
    }

    if (mod) {
        miners.erase(miners.begin(), miners.begin() + nex);
        reverse(miners.begin(), miners.end());
        while(avm.size()) {
            miners.push_back(avm.top());
            avm.pop();
        }
        reverse(miners.begin(), miners.end());
    }

    return { unm, low };
}

int N;
int cave[MAXN];
vector<int> adj[MAXN];

int path[MAXN];
int parent[MAXN];

void mini(int loc, int par) {
    parent[loc] = par;
    path[loc] = min(cave[loc], path[par]);
    for (int c : adj[loc]) 
        if (c != par)
            mini(c, loc);
}

int use;

vector<int> avail;
void collect(int loc, int par, int abv) {
    if (loc != par) abv = min(abv, cave[loc]);
    if (abv <= use) return;

    avail.push_back(abv);

    for (int c : adj[loc]) {
        if (c != parent[loc])
        collect(c, loc, abv);
    }
}

vector<int> sad_miners;

bool doit(int loc, int par, int raise) {
    for (int c : adj[loc]) {
        if (c != par) {
            if (doit(c, loc, raise)) return true;
        }
    }

    if (cave[loc] <= use) {
        int would = cave[loc] + raise;
        if (par != loc) would = min(would, path[par]);

        if (would > use) {
            avail.clear();
            collect(loc, loc, would);

            // try to put all the sad miners in the raised caves
            if (avail.size() < sad_miners.size()) return false;
            pair<int, int> res = match(sad_miners, avail, false);
            return (avail.size() - res.first == sad_miners.size());
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> cave[i];
        path[i] = cave[i];
    }

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    int K;
    cin >> K;

    sad_miners.resize(N);
    for (int i = 0; i < N; i++) {
        if (i < K) cin >> sad_miners[i];
        else sad_miners[i] = 0;
    }

    mini(0, 0);

    vector<int> caves_vec(N);
    for (int i = 0; i < N; i++) caves_vec[i] = path[i];
    use = match(sad_miners, caves_vec, true).second;

    if (!sad_miners.size()) {
        cout << 0 << "\n";
        return 0;
    }

    int ans = INF;
    int lo = 0, hi = INF;

    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (doit(0, 0, mi)) {
            ans = mi;
            hi = mi - 1;
        }
        else lo = mi + 1;
    }

    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
}