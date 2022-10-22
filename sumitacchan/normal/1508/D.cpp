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


signed main(){

    int n; cin >> n;
    vec x(n), y(n), a(n);
    REP(i, n){
        cin >> x[i] >> y[i] >> a[i];
        a[i]--;
    }

    int i0 = -1;
    REP(i, n) if(a[i] != i){
        i0 = i;
        break;
    }
    if(i0 == -1){
        Out(0);
        return 0;
    }
    //debug(i0);

    UnionFind UF(n);
    REP(i, n) UF.unite(i, a[i]);

    using Pdi = pair<long double, int>;
    using v_Pdi = vector<Pdi>;
    v_Pdi p;
    vector<long double> theta(n);
    REP(i, n) if(i != i0){
        theta[i] = atan2l((long double)(y[i] - y[i0]), (long double)(x[i] - x[i0]));
        p.pb(Pdi(theta[i], i));
    }
    Sort(p);

    int k0 = 0;
    double pi = 3.1415926535897932384626434L;
    REP(i, n - 2){
        if(p[i + 1].fi - p[i].fi > pi) k0 = i + 1;
    }

    v_Pii ans;
    while(UF.n_cc > 1){
        REP(i, n - 2) {
            int j = p[(i + k0) % (n - 1)].se, k = p[(i + 1 + k0) % (n - 1)].se;
            if(!UF.is_union(j, k)){
                ans.pb(Pii(j, k));
                swap(a[j], a[k]);
                UF.unite(j, k);
            }
        }
    }

    while(a[i0] != i0){
        int j0 = a[i0];
        ans.pb(Pii(i0, j0));
        swap(a[i0], a[j0]);
    }

    REP(i, n) assert(a[i] == i);

    Out(SZ(ans));
    REP(i, SZ(ans)) cout << ans[i].fi + 1 << " " << ans[i].se + 1 << "\n";

    return 0;
}