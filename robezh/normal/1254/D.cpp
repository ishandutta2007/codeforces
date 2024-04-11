#include <bits/stdc++.h>
using namespace std;

const int N = 150050, SQRT = 1000, mod = 998244353;
typedef long long ll;
typedef pair<int, int> P;

int n, m;
vector<int> G[N];
int sub[N];
int dfn[N], in[N], out[N], tim = 0;
int par[N];
vector<int> bs[N];
ll tsum[N];
ll add[N], subsum[N];
ll upsum[N];
vector<P> buf;
ll invn = 0;

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

void dfs(int v, int p) {
    sub[v] = 1;
    par[v] = p;
    for(int i = 0; i < G[v].size(); i++) {
        int nxt = G[v][i];
        if(nxt == p) continue;
        dfs(nxt, v);
        sub[v] += sub[nxt];
        if(G[v][0] == p || sub[nxt] > sub[G[v][0]]) swap(G[v][i], G[v][0]);
    }
}

void get_dfn(int v, int p) {
    in[v] = tim;
    dfn[tim++] = v;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        get_dfn(nxt, v);
        if(nxt != G[v][0]) {
            for(int j = 0; j < sub[nxt]; j++) {
                bs[v].push_back(sub[nxt]);
            }
        }
    }
    out[v] = tim - 1;
}

int get_subsize(int v, int u) {
    if(u == v) return n;
    if(in[u] < in[v] || in[u] > out[v]) return sub[v];
    int big = G[v][0];
    if(in[big] <= in[u] && in[u] <= out[big]) return n - sub[big];
    return n - bs[v][in[u] - in[v] - sub[big] - 1];
}


void inc(ll &to, ll x) {
    to += x;
    if(to >= mod) to -= mod;
}

void calc() {
    for(int i = n - 1; i >= 0; i--) {
        int v = dfn[i], p = par[v];
        subsum[v] = add[v] * sub[v] % mod;
        for(int nxt : G[v]) {
            if(nxt == p) continue;
            inc(subsum[v], subsum[nxt]);
        }
    }
}

void reroot() {
    for(int i = 0; i < n; i++) {
        int v = dfn[i], p = par[v];
        ll ajsum = (subsum[v] + upsum[v] - add[v] * sub[v]);
        ll curres = (ajsum + add[v] * n) % mod;
        if(curres < 0) curres += mod;
        inc(tsum[v], curres);
        for(int nxt : G[v]) {
            if(nxt == p) continue;
            upsum[nxt] = (ajsum - subsum[nxt] + (n - sub[nxt]) * add[v]) % mod;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    invn = fp(n, mod - 2);
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    get_dfn(0, -1);

    for(int i = 0; i < m; i++) {
        int tp;
        cin >> tp;
        if(tp == 1) {
            int v, d; cin >> v >> d; v--;
            buf.push_back({v, d});
        }
        else {
            int v; cin >> v; v--;
            ll curres = tsum[v];
            for(auto p : buf) {
                inc(curres, 1LL * get_subsize(p.first, v) * p.second % mod);
//                cout << p.first << ", " << curres << endl;
            }
            cout << curres * invn % mod << '\n';
        }
        if((buf.size() + 1) % SQRT == 0) {

            for(auto p : buf) inc(add[p.first], p.second);

            calc();
            reroot();

            for(auto p : buf) inc(add[p.first], mod - p.second);
            buf.clear();
        }
    }

}