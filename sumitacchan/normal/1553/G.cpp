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
//#define int long long
//#define INF 1000000000000000000
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
    int n_cc;

    UnionFind(int N){
        par = vector<int>(N);
        REP(i, N) par[i] = i;
        sz = vector<int>(N, 1);
        n_cc = N;
    }

    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;

        if(sz[x] < sz[y]) swap(x, y);

        par[y] = x;
        sz[x] += sz[y];
        n_cc--;
    }

    bool is_union(int x, int y){
        x = find(x);
        y = find(y);
        return x == y;
    }

    int union_size(int x){
        return sz[find(x)];
    }

};

vec prime_list(int MAX_N){

    vector<bool> is_prime(MAX_N + 1, true);
    vec prime(0);
    is_prime[0] = false;
    is_prime[1] = false;

    FOR(i, 2, MAX_N + 1){
        if(is_prime[i]){
            prime.push_back(i);
            int tmp = i * 2;
            while(tmp <= MAX_N){
                is_prime[tmp] = false;
                tmp += i;
            }
        }
    }

    return prime;
}

signed main(){

    const int M = 1000001;
    vec prime = prime_list(M);
    
    int n, q; cin >> n >> q;
    vec a(n); cin >> a;
    v_bool exist(M + 1, false);
    REP(i, n) exist[a[i]] = true;
    UnionFind UF(M + SZ(prime));
    REP(i, SZ(prime)){
        for(int j = prime[i]; j <= M; j += prime[i]){
            if(exist[j]) UF.unite(j, i + M);
        }
    }

    vector<set<int>> valid(M + SZ(prime) + 1);
    mat ds(M + 1);
    REP(i, SZ(prime)){
        for(int j = prime[i]; j <= M; j += prime[i]) if(exist[j - 1]){
            int x0 = UF.find(j - 1), y0 = UF.find(i + M);
            if(x0 > y0) swap(x0, y0);
            if(x0 != y0) valid[x0].insert(y0);
            
            for(int x: ds[j]){
                int x0 = UF.find(x + M), y0 = UF.find(i + M);
                if(x0 > y0) swap(x0, y0);
                if(x0 != y0) valid[x0].insert(y0);
            }
            ds[j].pb(i);
        }
    }

    vec ans(q);
    REP(i, q){
        int s, t; cin >> s >> t;
        s--; t--;
        int s0 = UF.find(a[s]), t0 = UF.find(a[t]);
        if(s0 > t0) swap(s0, t0);

        if(s0 == t0) ans[i] = 0;
        else if(valid[s0].count(t0)) ans[i] = 1;
        else ans[i] = 2;
    }
    REP(i, q) cout << ans[i] << '\n';

    return 0;
}