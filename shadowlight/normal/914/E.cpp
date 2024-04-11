#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = (1 << 21);
const double EPS = 1e-8;
const ll LOGN = 20;

vector <vector <ll> > gr;

vector <ll> a;
vector <ll> cnt;
vector <bool> used;

void dfs(ll v, ll p) {
    cnt[v] = 1;
    for (ll u : gr[v]) {
        if (u == p || used[u]) continue;
        dfs(u, v);
        cnt[v] += cnt[u];
    }
}

vector <ll> sums(MAXN, 0);
vector <ll> res;

void calc(ll v, ll p, ll mask, ll add) {
    mask ^= (1 << a[v]);
    sums[mask] += add;
    for (ll u : gr[v]) {
        if (u == p || used[u]) continue;
        calc(u, v, mask, add);
    }
}

ll good = 0;

ll force(ll v, ll p, ll mask) {
    //cout << v << " " << p << "\n";
    //system("pause");
    mask ^= (1 << a[v]);
    ll mask1 = mask;
    ll all = 0;
    all += sums[mask1];
    if (!mask1) {
        good++;
        all++;
    }
    for (ll t = 0; t < LOGN; t++) {
        //assert((mask1 ^ (1 << t)) < MAXN);
        all += sums[mask1 ^ (1 << t)];
        if (!(mask1 ^ (1 << t))) {
            good++;
            all++;
        }
    }
    for (ll u : gr[v]) {
        if (u == p || used[u]) continue;
        all += force(u, v, mask);
    }
    //cout << v << " " << p << " " << all << "\n";
    res[v] += all;
    return all;
}

void go(ll v) {
    //cout << v << "\n";
    dfs(v, -1);
    //cout << "kek\n";
    ll p = -1;
    ll all = cnt[v];
    while (true) {
        bool fl = false;
        for (ll u : gr[v]) {
            if (u == p || used[u]) continue;
            if (2 * cnt[u] > all) {
                fl = true;
                p = v;
                v = u;
                break;
            }
        }
        if (!fl) break;
    }
    //cout << v << "\n";
    used[v] = 1;
    for (ll u : gr[v]) {
        if (used[u]) continue;
        calc(u, v, 0, 1);
    }
    ll add = 0;
    for (ll u : gr[v]) {
        if (used[u]) continue;
        calc(u, v, 0, -1);
        good = 0;
        add += force(u, v, (1 << a[v]));
        res[v] += good;
        add -= good;
        //cout << u << " " << v << " " << force(u, v, (1 << a[v])) << "\n";
        //cout << "ALL\n";
        calc(u, v, 0, 1);
    }
    res[v] += add / 2 + 1;
    for (ll u : gr[v]) {
        if (used[u]) continue;
        calc(u, v, 0, -1);
    }
    for (ll u : gr[v]) {
        if (used[u]) continue;
        go(u);
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
    ll n;
    cin >> n;
    res.resize(n, 0);
    cnt.resize(n, 0);
    a.resize(n);
    used.resize(n, false);
    gr.resize(n);
    for (ll i = 1; i < n; i++) {
        ll v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    for (ll i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i] = c - 'a';
    }
    go(0);
    for (ll i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}