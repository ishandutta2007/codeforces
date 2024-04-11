#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void agg(vi& a, const vi& b) {
    if (b.empty()) return;
    if (a.empty()) { a = b; return; }
    if (a[0] == -1) return;
    if (a != b) a = { -1 };
}

bool fail(const vi& a) {
    return (!a.empty()) && a[0] == -1;
}

void extend(vi& a, int br) {
    if (fail(a)) return;
    if (br == 0) { a = { 0 }; return; }
    a.back()++;
    if (br > 1) { a.push_back(br); a.push_back(0); }
}

void go(vvi& adj, vi& u, vi& v, vvi& look, int loc, int par) {
    int qua = 0;
    for (int e : adj[loc]) if ((e^1) != par) {
        go(adj, u, v, look, v[e], e);
        qua++;
        if (par != -1) agg(look[par], look[e]);
    }
    if (par != -1) extend(look[par], qua);
}

void again(vvi& adj, vi& u, vi& v, vvi& look, int loc, int par) {
    vi arc;
    vvi nbrs;
    for (int e : adj[loc]) {
        assert(!look[e].empty());
        arc.push_back(e);
        nbrs.push_back(look[e]);
    }

    vvi pref(nbrs.size() + 1);
    for (int i = 0; i < sz(nbrs); i++) {
        agg(pref[i+1], pref[i]);
        agg(pref[i+1], nbrs[i]);
    }

    vvi suff(nbrs.size() + 1);
    for (int i = sz(nbrs) - 1; i >= 0; i--) {
        agg(suff[i], suff[i+1]);
        agg(suff[i], nbrs[i]);
    }

    for (int i = 0; i < sz(nbrs); i++) {
        if ((arc[i]^1) != par) {
            agg(look[arc[i]^1], pref[i]);
            agg(look[arc[i]^1], suff[i+1]);
            extend(look[arc[i]^1], sz(nbrs) - 1);
        }
    }

    for (int e : adj[loc]) if ((e^1) != par) {
        again(adj, u, v, look, v[e], e);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, E;
    cin >> N;
    E = 2 * N - 2;

    vvi adj(N);
    vi u(E), v(E);

    for (int i = 0; i < E; i += 2) {
        cin >> u[i] >> v[i];
        adj[--u[i]].push_back(i);
        adj[--v[i]].push_back(i + 1);
        u[i + 1] = v[i];
        v[i + 1] = u[i];
    }

    vvi look(E);
    go(adj, u, v, look, 0, -1);
    again(adj, u, v, look, 0, -1);

    /*for (int e = 0; e < E; e++) {
        cout << e << " (" << u[e]+1 << "->" << v[e]+1 << "): ";
        WATCHC(look[e]);
    }*/

    for (int r = 0; r < N; r++) {
        vi res = {};
        for (int e : adj[r]) {
            agg(res, look[e]);
        }
        if (!fail(res)) {
            cout << r + 1 << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}