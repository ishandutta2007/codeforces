#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

int n, mod;
set<pii> G[N];
int sub[N];

int dfs1(int v, int p){
    sub[v] = 1;
    for(auto &e : G[v])
        if(e.first != p)
            sub[v] += dfs1(e.first, v);
    return sub[v];
}

int dfs2(int v, int p, int nn){
    for(auto &e : G[v]){
        if(e.first != p && sub[e.first] > nn/2) return dfs2(e.first, v, nn);
    }
    return v;
}

map<ll, int> mp;
ll pw10[N], ipw10[N];


ll fp(int x, int p) {
    if(p == 0) return 1;
    ll hf = fp(x, p / 2);
    return p % 2 ? hf * hf % mod * x % mod : hf * hf % mod;
}


void add(int v, int p, int d, ll cur, int delta) {
    cur %= mod;
    mp[cur] += delta;
//    cout << cur << " adding " << delta << endl;
    for(auto e : G[v]) {
        if(e.first == p) continue;
        add(e.first, v, d + 1, (pw10[d] * e.second + cur) % mod, delta);
    }
}



ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = a;
    if(b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else {
        x = 1; y = 0;
    }
    return d;
}

ll res = 0;

void process(int v, int p, int d, ll cur) {
    cur %= mod;
    res += mp[(mod - cur) * ipw10[d] % mod];
//    cout << v << ": " << cur << " " << mp[(mod - cur) * ipw10[d] % mod] << endl;
    for(auto e : G[v]) {
        if(e.first == p) continue;;
        process(e.first, v, d + 1, (cur * 10 + e.second) % mod);
    }
}

void decompose(int v, int p){
    dfs1(v, -1);
    int centroid = dfs2(v, -1, sub[v]);

    mp.clear();
    add(centroid, -1, 0, 0, 1);
    res += mp[0] - 1;


//    cout << "c: " << centroid << endl;
    for(auto &e : G[centroid]) {
        add(e.first, centroid, 1, e.second, -1);
        process(e.first, centroid, 1, e.second);
        add(e.first, centroid, 1, e.second, 1);
    }



    for(auto &e : G[centroid]){
        G[e.first].erase({centroid, e.second});
        decompose(e.first, centroid);
    }
    G[centroid].clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> mod;
    if(mod == 1) {
        cout << 1LL * n * (n - 1) << '\n';
        return 0;
    }
    pw10[0] = 1;
    ipw10[0] = 1;
    ll iv10, tmp;
    extgcd(10, mod, iv10, tmp);
    iv10 = (iv10 % mod + mod) % mod;

//    int iv10 = fp(10, mod - 2);
//    cout << iv10 << endl;
    rep(i, 1, N) {
        pw10[i] = pw10[i - 1] * 10 % mod;
        ipw10[i] = ipw10[i - 1] * iv10 % mod;
//        ipw10[i] = fp(pw10[i], mod - 2);
//        cout << pw10[i] << " " << ipw10[i] << endl;
        assert(pw10[i] * ipw10[i] % mod == 1);
    }
    rep(i, 0, n - 1) {
        int a, b, c; cin >> a >> b >> c;
        G[a].insert({b, c});
        G[b].insert({a, c});
    }

    decompose(0, -1);
    cout << res << '\n';

}