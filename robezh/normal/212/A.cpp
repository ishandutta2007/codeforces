#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 10005;

map<pii, pii> to;
//map<pii, int> col;
int D = 0;
int n;
int L, R, m;

int res[N];
vector<pii> edges;
int tcnt = 0;
int Lcur[N], Rcur[N];
int Lcnt[N], Rcnt[N];

void add_edge(int x, int y) {
    edges.push_back({x, y});
//    mp[{x, y}] = idx;/**/
}


void setcol(int x, int y, int c, int idx) {
    to[{x, c}] = {y, idx};
    to[{y, c}] = {x, idx};
    res[idx] = c;
}

void find(int x, int y, int id, int c0, int c1) {
    int n0 = c0, n1 = c1;
    vi vs = {x, y};
    vi idx = {id};
    int cur = y;
    while(to.count({cur, c0})) {
        idx.push_back(to[{cur, c0}].second);
        cur = to[{cur, c0}].first;
        vs.push_back(cur);
        swap(c0, c1);
    }
    c0 = n0, c1 = n1;
    for(int i = 0; i + 1 < sz(vs); i++) {
        setcol(vs[i], vs[i + 1], c0, idx[i]);
        if(i + 1 == sz(vs) - 1) to.erase({vs[i + 1], c1});
        swap(c0, c1);
    }

}

void color(int x, int y, int idx) {
    int c0 = -1, c1 = -1;
    rep(c, 1, D + 1) {
        if (!to.count({x, c}) && !to.count({y, c})) {
            setcol(x, y, c, idx);
            return;
        } else if(!to.count({x, c})) {
            c0 = c;
        } else if(!to.count({y, c})) {
            c1 = c;
        }
    }
    assert(c0 != -1 && c1 != -1);
    find(x, y, idx, c0, c1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> R >> m >> D;
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
//        if(u > v) swap(u, v);
        if(Lcur[u] == 0 || Lcnt[u] == D) {
            Lcur[u] = ++tcnt;
            Lcnt[u] = 0;
        }
        if(Rcur[v] == 0 || Rcnt[v] == D) {
            Rcur[v] = ++tcnt;
            Rcnt[v] = 0;
        }
        Lcnt[u]++;
        Rcnt[v]++;
        add_edge(Lcur[u], Rcur[v]);
    }
    int imbal = 0;
    rep(i, 1, L + 1) imbal += (Lcnt[i] % D != 0);
    rep(i, 1, R + 1) imbal += (Rcnt[i] % D != 0);

//    tcnt = 2 * n;
    rep(i, 0, m) {
        color(edges[i].first, edges[i].second, i);
    }
    cout << imbal << endl;

    rep(i, 0, m) cout << res[i] << endl;
//    cout << endl;

}