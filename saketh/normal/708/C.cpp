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
typedef vector<bool> vb;

void dfs1(int loc, int par, int N, vvi &adj, vi &subt, vi &down, vi &fat) {
    subt[loc] = 1;
    int lrg = loc;

    for (int nbr : adj[loc]) {
        if (nbr != par) {
            dfs1(nbr, loc, N, adj, subt, down, fat);
            subt[loc] += subt[nbr];

            if (lrg == loc || subt[nbr] > subt[lrg])
                lrg = nbr;
        }
    }

    if (subt[lrg] > N/2) {
        down[loc] = down[lrg];
        fat[loc] = lrg;
    }
    else 
        down[loc] = lrg;
}

void dfs2(int loc, int par, int N, vvi &adj, vi &subt, vi &down, vi &fat, vi &updel, vb &fin) {
    int sizeup = N - subt[loc];
    bool centr = false;

    if (fat[loc] == -1 && sizeup <= N / 2) {
        // location is already a centroid, special case~
        fin[loc] = true;

        if (sizeup >= subt[down[loc]]) {
            updel[loc] = sizeup;
        } else centr = true;
    } else {
        if (sizeup > N / 2) {
            int big = sizeup - updel[par];
            fin[loc] = big <= N / 2;
            updel[loc] = updel[par];
        } else {
            int big = subt[fat[loc]] - subt[down[loc]];
            fin[loc] = big <= N / 2;
            // we would never come up here from the big subtree, so this is ok
            updel[loc] = subt[down[loc]];
        }
    }

    for (int nbr : adj[loc]) {
        if (nbr == par) continue;

        if (centr) {
            int biggest = down[loc];
            if (nbr == biggest) {
                int snd = sizeup;
                for (int nbr2 : adj[loc]) {
                    if (nbr2 != nbr && nbr2 != par)
                        snd = max(snd, subt[nbr2]);
                }
                updel[loc] = snd;
            } else {
                updel[loc] = subt[down[loc]];
            }
        } 

        dfs2(nbr, loc, N, adj, subt, down, fat, updel, fin);
    }
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

    vi subt(N), down(N), fat(N, -1);
    dfs1(0, 0, N, adj, subt, down, fat);

    vi updel(N);
    vb fin(N);
    dfs2(0, 0, N, adj, subt, down, fat, updel, fin);

    for (int i = 0; i < N; i++) {
        cout << fin[i] << " ";
    }
    cout << endl;

    return 0;
}