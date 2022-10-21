#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> poly;

const int N = 1505, mod = 998244353;

struct edge {
    int a, b, cost;
};

int n;
vector<edge> es;

poly mul(poly &v1, poly &v2) {
    poly res(sz(v1) + sz(v2) - 1, 0);
    rep(i, 0, sz(v1)) {
        rep(j, 0, sz(v2)) {
            res[i + j] += v1[i] * v2[j] % mod;
            if(res[i + j] >= mod) res[i + j] -= mod;
        }
    }
    return res;
}

int f[N], sz[N], esz[N];
poly p[N];

int find(int u) {return f[u] == u ? u : f[u] = find(f[u]);}

void unite(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) {
        esz[v] += 1;

    } else {
        f[u] = v;
        sz[v] += sz[u];
        esz[v] += esz[u];
        esz[v]++;
//        cout << "multing " << u << " and " << v << endl;
        p[v] = mul(p[v], p[u]);
    }
    if(esz[v] == 1LL * sz[v] * (sz[v] - 1) / 2) {
        p[v][1]++;
        if(p[v][1] >= mod) p[v][1] -= mod;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        rep(j, 0, n) {
            int cost; cin >> cost;
            if(i < j) es.push_back({i, j, cost});
        }
    }
    sort(all(es), [](const edge &e1, const edge &e2) {
        return e1.cost < e2.cost;
    });
    for(int i = 0; i < n; i++) {
        f[i] = i;
        sz[i] = 1;
        esz[i] = 0;
        p[i] = {0, 1};
    }
    for(auto &e : es) {
        unite(e.a, e.b);
    }
    rep(i, 1, n + 1) cout << p[find(0)][i] << " ";
    cout << '\n';


}