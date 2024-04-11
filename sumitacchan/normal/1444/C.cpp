#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define bit(n) (1LL<<(n))
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) { cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl; }
#define mdebug(m) { cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;} }
#define pb push_back
#define fi first
#define se second
#define int long long
#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < v.size(); i++) { cout << v[i]; if(i != v.size() - 1) cout << endl; }; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p){ cout << '(' << p.first << ',' << p.second << ')'; return os; }
template<typename T> void Out(T x) { cout << x << endl; }
template<typename T1, typename T2> void chOut(bool f, T1 y, T2 n) { if(f) Out(y); else Out(n); }

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using v_bool = vector<bool>;
using v_Pii = vector<Pii>;

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

const int mod = 1000000007;
//const int mod = 998244353;

struct UnionFind
{
    vector<int> par, sz;
    map<int, int> memory_par, memory_sz;

    UnionFind(int N){
        par = vector<int>(N);
        REP(i, N) par[i] = i;
        sz = vector<int>(N, 1);
    }

    int find(int x){
        if(par[x] == x) return x;
        else return find(par[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;

        if(sz[x] < sz[y]) swap(x, y);

        if(memory_par.count(y) == 0) memory_par[y] = par[y];
        par[y] = x;
        if(memory_par.count(x) == 0) memory_sz[x] = sz[x];
        sz[x] += sz[y];
    }

    bool is_union(int x, int y){
        x = find(x);
        y = find(y);
        return x == y;
    }

    int union_size(int x){
        return sz[find(x)];
    }

    void fix(){
        memory_par.erase(all(memory_par));
        memory_sz.erase(all(memory_sz));
    }
    void reverse(){
        for(Pii m: memory_par) par[m.fi] = m.se;
        for(Pii m: memory_sz) sz[m.fi] = m.se;
        fix();
    }

};


signed main(){

    int n, m, k; cin >> n >> m >> k;
    vec c(n); cin >> c;
    REP(i, n) c[i]--;

    UnionFind UF(2 * n);
    vec a(m), b(m);
    v_bool ok(k, true);
    map<Pii, vec> es;
    REP(i, m){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;

        if(c[a[i]] == c[b[i]]){
            UF.unite(a[i], b[i] + n);
            UF.unite(a[i] + n, b[i]);
        }else{
            int c1 = c[a[i]], c2 = c[b[i]];
            if(c1 > c2) swap(c1, c2);
            es[Pii(c1, c2)].pb(i);
        }
    }
    REP(i, n) if(UF.is_union(i, i + n)) ok[c[i]] = false;

    int n_ok = 0;
    REP(i, k) if(ok[i]) n_ok++;
    int ans = n_ok * (n_ok - 1) / 2;

    UF.fix();

    for(auto e: es){
        int c1 = e.fi.fi, c2 = e.fi.se;
        vec is = e.se;
        if(!ok[c1] || !ok[c2]) continue;

        bool valid = true;
        for(int i: is){
            UF.unite(a[i], b[i] + n);
            UF.unite(a[i] + n, b[i]);

            if(UF.is_union(a[i], a[i] + n)){
                valid = false;
                break;
            }
        }
        if(!valid) ans--;

        UF.reverse();
    }

    Out(ans);

    return 0;
}