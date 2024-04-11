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

int num_edges(int node, vi &nbrs, int pref) {
    int v1 = 0, v2 = 0;
    if (pref > 1) {
        cout << "? " << pref;
        for (int i = 0; i < pref; i++)
            cout << " " << nbrs[i];
        cout << endl;
        cin >> v1;
    }
    if (pref > 0) {
        cout << "? " << pref + 1 << " " << node;
        for (int i = 0; i < pref; i++)
            cout << " " << nbrs[i];
        cout << endl;
        cin >> v2;
    }
    return v2 - v1;
}

bool find_path(vvi &adj, int v1, int v2, int par, vi &res) {
    res.push_back(v1);
    if (v1 == v2) return true;
    for (int nbr : adj[v1]) {
        if (nbr != par)
            if(find_path(adj, nbr, v2, v1, res))
                return true;
    }
    res.pop_back();
    return false;
}

int find_nbr(int node, vi &poss) {
    if (num_edges(node, poss, poss.size()) == 0)
        return -1;
    int res = -1, lo = 0, hi = poss.size() - 1;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        int edges = num_edges(node, poss, mi + 1);
        if (edges >= 1) {
            res = mi;
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }
    return poss[res];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vvi adj(N + 1);
    vi comp(N + 1);
    vb color(N + 1);
    vector<vb> is_nbr(N + 1, vb(N + 1, false));

    for (int i = 1; i <= N; i++) {
        if (comp[i]) continue;
        comp[i] = i;
        queue<int> bfs({i});

        vi p1 = { i }, p2;
        int cz = 1;

        while (!bfs.empty()) {
            int loc = bfs.front();
            bfs.pop();
            while (true) {
                vi cand;
                for (int j = 1; j <= N; j++)
                    if (comp[j] == 0)
                        cand.push_back(j);
                int nbr = find_nbr(loc, cand);
                if (nbr == -1) break;

                adj[loc].push_back(nbr);
                is_nbr[loc][nbr] = true;
                adj[nbr].push_back(loc);
                is_nbr[nbr][loc] = true;

                comp[nbr] = i;
                color[nbr] = !color[loc];
                if (color[nbr]) p2.push_back(nbr);
                else p1.push_back(nbr);
                bfs.push(nbr);
            }
        }

        auto print_cycle = [&](int v1, int v2) {
            vi path;
            find_path(adj, v1, v2, 0, path);
            cout << "N " << path.size() << endl;
            for (int v : path) cout << v << " ";
            cout << endl;
            exit(0);
        };

        auto find_cycle = [&](vi &grp) {
            for (int v : grp) {
                vi cand;
                for (int u : grp)
                    if (u != v)
                        cand.push_back(u);
                int nbr = find_nbr(v, cand);
                if (nbr != -1) {
                    print_cycle(v, nbr);
                }
            }
        };

        find_cycle(p1);
        find_cycle(p2);
    }

    vi part;
    for (int i = 1; i <= N; i++)
        if (!color[i])
            part.push_back(i);
    cout << "Y " << part.size() << endl;
    for (int v : part) cout << v << " ";
    cout << endl;

    return 0;
}