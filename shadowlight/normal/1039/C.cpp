#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll power(ll a, ll k) {
    if (!k) {
        return 1;
    }
    ll b = power(a, k / 2);
    b = b * b % INF;
    if (k % 2) {
        return a * b % INF;
    } else {
        return b;
    }
}

vector <vector <ll> > gr;

vector <ll> p, r;

ll all_sz = 0;

ll get(ll v) {
    return (p[v] == v ? v : p[v] = get(p[v]));
}

bool uni(ll v, ll u) {
    v = p[v];
    u = p[u];
    if (v == u) {
        return false;
    }
    if (r[v] == r[u]) {
        r[u]++;
    }
    if (r[v] > r[u]) {
        swap(v, u);
    }
    p[v] = u;
    all_sz--;
    return true;
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
    ll n, m, k;
    cin >> n >> m >> k;
    p.resize(n, 0);
    iota(p.begin(), p.end(), 0);
    r.resize(n, 0);
    vector <ll> c(n);
    for (ll i = 0; i < n; i++) {
        cin >> c[i];
    }
    ll all = power(2, n + k);
    gr.resize(n);
    map <ll, vector <pair <ll, ll> > > d;
    for (ll i = 0; i < m; i++) {
        ll v, u;
        cin >> v >> u;
        v--, u--;
        d[c[v] ^ c[u]].push_back({v, u});
    }
    ll bad = 0;
    for (auto pt : d) {
        all_sz = n;
        //cout << pt.first << ":\n";
        set <ll> used;
        for (auto t : pt.second) {
            ll v = t.first, u = t.second;
            used.insert(v);
            used.insert(u);
            if (get(v) == get(u)) continue;
            bad = (bad + power(2, all_sz - 1)) % INF;
            uni(v, u);
        }
        //cout << "\n";
        for (ll v : used) {
            p[v] = v;
            r[v] = 0;
        }
    }
    cout << (all - bad + INF) % INF;
}