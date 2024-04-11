#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

// 2 0 0 -2 0  0 0 0 0 0
// 2 0 3 -2 0  

struct BIT {
    ll b[MAXN];
    BIT() { memset(b, 0, sizeof b); };
    
    void upd(int p, int v) {
        for(; p < MAXN; p += (p & -p))
            b[p] += v;
    }
    
    ll sum(int p) {
        ll res = 0;
        for(; p; p -= (p & -p))
            res += b[p];
        return res % MOD;
    }
};

struct rangesum {
    BIT sl, co;
    void add(int l, int r, ll v) {
        //cout << "add " << l << " " << r << " " << v << endl;
        r++;
        sl.upd(l, v);
        sl.upd(r, -v);
        co.upd(l, -v*(l - 1)%MOD);
        co.upd(r, v*(r - 1)%MOD);
    }
    
    ll sum(int l, int r) {
        l--;
        ll al = sl.sum(l), bl = co.sum(l), ar = sl.sum(r), br = co.sum(r);
        //cout << l << " " << r << " " << al << " " << bl << " " << ar << " " << br << endl;
        ll y = (ar * r + br) % MOD, x = (al * l + bl) % MOD;
        return (y >= x ? y - x : y - x + MOD);
    }
} cur, tot;

int l[MAXN], r[MAXN], w[MAXN], sz[MAXN], used[MAXN];
ll inv[MAXN], ans = 0, ways = 1;
vector<int> adj[MAXN];

ll _inv(ll b) {
    ll e = MOD - 2, res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

void dfs_sz(int s, int p = -1) {
    sz[s] = 1;
    for(auto v : adj[s]) {
        if(v == p || used[v])
            continue;
        dfs_sz(v, s);
        sz[s] += sz[v];
    }
}

int get_cen(int s, int rt, int p = -1) {
    for(auto v : adj[s]) {
        if(v == p || used[v])
            continue;
        if(2*sz[v] > sz[rt])
            return get_cen(v, rt, s);
    }
    return s;
}

void addify(int s, int p, int di) {
    ll den = inv[w[s]], both = (den * di) % MOD;
    ans = (ans + both * cur.sum(l[s], r[s])) % MOD;
    ans = (ans + den * tot.sum(l[s], r[s])) % MOD;
    for(auto v : adj[s]) {
        if(v == p || used[v])
            continue;
        addify(v, s, di + 1);
    }
}

void modify(int s, int p, int di, int sg = 1) {
    ll den = inv[w[s]], both = (den * di) % MOD;
    cur.add(l[s], r[s], den * sg);
    tot.add(l[s], r[s], both * sg);
    for(auto v : adj[s]) {
        if(v == p || used[v])
            continue;
        modify(v, s, di + 1, sg);
    }
}

void solve(int s) {
    dfs_sz(s);
    int cen = get_cen(s, s);
    
    //cout << "default = " << tot.sum(1, MAXN - 2) << " " << cur.sum(1, MAXN - 2) << '\n';
    cur.add(l[cen], r[cen], inv[w[cen]]);
    
    for(auto v : adj[cen]) {
        if(used[v])
            continue;
        addify(v, cen, 1);
        modify(v, cen, 1);
        //cout << "ended " << cen << " - " << v << " ans = " << (ways * ans) % MOD << '\n';
        
    }
    for(auto v : adj[cen]) {
        if(used[v])
            continue;
        modify(v, cen, 1, -1);
    }
    cur.add(l[cen], r[cen], -inv[w[cen]]);
    //cout << "ended = " << tot.sum(1, MAXN - 2) << " " << cur.sum(1, MAXN - 2) << '\n';
        
    used[cen] = 1;
    for(auto v : adj[cen])
        if(!used[v])
            solve(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < MAXN; i++)
        inv[i] = _inv(i);
    for(int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        w[i] = r[i] - l[i] + 1;
        ways = (ways * w[i]) % MOD;
    }
    for(int i = 0; i < n - 1; i++) {
        int u ,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve(1);
    cout << (ways * ans) % MOD << '\n';
}