#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

array<ll, 3> go(vvi &adj, array<ll, 3> &global, int loc, int par) {
    ll sum = 0, even = 0, odd = 0;
    for (int nbr : adj[loc]) {
        if (nbr == par) continue;
        auto res = go(adj, global, nbr, loc);
        global[0] += sum * (res[1] + res[2])
                   + (res[0] + res[1] + res[2]) * (even + odd);
        global[1] += even * res[2] + odd * res[1];
        global[2] += even * res[1] + odd * res[2];

        sum += res[0] + res[1] + res[2];
        even += res[2];
        odd += res[1];
    }

    global[0] += sum;
    global[1] += even;
    global[2] += odd;

    even++;
    return { sum, even, odd };
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

    array<ll, 3> res = { 0, 0, 0 };
    go(adj, res, 0, 0);
    assert(res[1] + res[2] == N * ll(N - 1) / 2);
    cout << (res[0] + res[2]) / 2 << endl;

    return 0;
}