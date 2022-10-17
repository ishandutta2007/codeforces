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

void calc_sum(int loc, int par, vvi &adj, vi &sum, vector<bool> &univ) {
    for (int nbr : adj[loc]) {
        if (nbr == par) continue;
        calc_sum(nbr, loc, adj, sum, univ);
        sum[loc] += sum[nbr];
    }
    sum[loc] += univ[loc];
}

int find_centroid(int loc, int par, vvi &adj, vi &sum, int K) {
    for (int nbr : adj[loc]) {
        if (nbr == par) continue;
        if (sum[nbr] > K / 2) return find_centroid(nbr, loc, adj, sum, K);
    }
    return loc;
}

ll calc_ans(int loc, int par, int dep, vvi &adj, vector<bool> &univ) {
    ll res = 0;
    for (int nbr : adj[loc]) {
        if (nbr == par) continue;
        res += calc_ans(nbr, loc, dep + 1, adj, univ);
    }
    if (univ[loc]) res += dep;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K;
    cin >> N >> K;
    K *= 2;

    vector<bool> univ(N);
    for (int i = 0; i < K; i++) {
        int where;
        cin >> where;
        univ[where - 1] = true;
    }

    vvi adj(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vi sum(N);
    calc_sum(0, 0, adj, sum, univ);

    int cent = find_centroid(0, 0, adj, sum, K);
    cout << calc_ans(cent, cent, 0, adj, univ) << "\n";

    return 0;
}