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

void go(vvi &adj, vi &depth, vi &subt, vi &tpar, int loc, int par) {
    subt[loc] = 1;
    tpar[loc] = par;
    for (int ch : adj[loc]) {
        if (ch == par) continue;
        depth[ch] = 1 + depth[loc];
        go(adj, depth, subt, tpar, ch, loc);
        subt[loc] += subt[ch];
    }
}

void solve() {
    int N;
    cin >> N;
    vvi adj(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vi depth(N), subt(N), tpar(N);
    go(adj, depth, subt, tpar, 0, 0);

    int K1;
    cin >> K1;
    vi mine(K1);
    set<int> in_mine;
    for (int i = 0; i < K1; i++) {
        cin >> mine[i];
        in_mine.insert(--mine[i]);
    }

    int K2;
    cin >> K2;
    vi his(K2);
    set<int> in_his;
    for (int i = 0; i < K2; i++) {
        cin >> his[i];
        in_his.insert(--his[i]);
    }

    int sh_in = mine[0];
    for (int i = 1; i < K1; i++) {
        if (depth[mine[i]] < depth[sh_in])
            sh_in = mine[i];
    }

    int resp;
    cout << "B " << *in_his.begin() + 1 << endl;
    cin >> resp;
    if (in_mine.count(resp - 1)) {
        cout << "C " << resp << endl;
        return;
    }

    int loc = resp - 1;
    while (depth[loc] > 0 && !in_mine.count(loc)) {
        loc = tpar[loc];
    }

    int query;
    if (in_mine.count(loc)) {
        query = loc;
    } else {
        query = sh_in;
    }

    cout << "A " << query + 1 << endl;
    cin >> resp;
    if (in_his.count(resp - 1)) {
        cout << "C " << query + 1 << endl;
        return;
    }

    cout << "C " << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }

    return 0;
}