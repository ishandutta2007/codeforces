#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <ll> > gr;
vector <bool> used;
vector <ll> segs;
vector <ll> add;
vector <ll> pred;

void dfs(ll v, ll p) {
    //cout << v << " " << p << "\n";
    if (used[v] && !add[v]) {
        ll minv = v, maxv = v;
        ll u = p;
        add[v] = 1;
        //cout << v << "\n";
        while (u != v) {
            minv = min(minv, u);
            maxv = max(maxv, u);
            add[u] = 1;
            //cout << u << "\n";
            u = pred[u];
        }
        segs[minv] = maxv - 1;
    }
    if (used[v]) {
        return;
    }
    used[v] = 1;
    pred[v] = p;
    for (ll u : gr[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n, m;
    cin >> n >> m;
    gr.resize(n);
    add.resize(n, 0);
    used.resize(n, false);
    pred.resize(n, -1);
    segs.resize(n, n - 1);
    for (ll i = 0; i < m; i++) {
        ll v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    for (ll i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i, -1);
        }
    }
    for (ll i = n - 2; i >= 0; i--) {
        segs[i] = min(segs[i], segs[i + 1]);
    }
//    for (ll i = 0; i < n; i++) {
//        cout << segs[i] << " ";
//    }
//    cout << "\n";
    vector <ll> pref(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + segs[i] - i + 1;
    }
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        ll x = upper_bound(segs.begin() + l, segs.end(), r) - segs.begin();
        //cout << x << "\n";
        ll res = 0;
        if (x > r) {
            res += pref[r + 1] - pref[l];
        } else {
            res += pref[x] - pref[l];
            //cout << res << "\n";
            res += (r - x + 2) * (r - x + 1) / 2;
        }
        cout << res << "\n";
    }
}