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

void color(int loc, vvi &adj, vi &colors, bool choice) {
    if (colors[loc] != -1) return;
    colors[loc] = choice;
    for (int nbr : adj[loc])
        color(nbr, adj, colors, !choice);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vvi adj(2 * N);
    for (int i = 0; i < N; i++) {
        adj[2 * i].push_back(2 * i + 1);
        adj[2 * i + 1].push_back(2 * i);
    }

    vector<int> a(N), b(N);

    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
        
        a[i] = u - 1;
        b[i] = v - 1;
    }

    vi res(2 * N, -1);
    for (int i = 0; i < 2 * N; i++) {
        if (res[i] != -1) continue;
        color(i, adj, res, 0);
    }

    for (int i = 0; i < N; i++) {
        cout << 1 + res[a[i]] << " " << 1 + res[b[i]] << "\n";
    }

    return 0;
}