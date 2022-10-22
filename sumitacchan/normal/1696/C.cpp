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
#define vdebug(v) { cout << #v << "=" << endl; REP(i_debug, (int)v.size()){ cout << v[i_debug] << ","; } cout << endl; }
#define mdebug(m) { cout << #m << "=" << endl; REP(i_debug, (int)m.size()){ REP(j_debug, (int)m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;} }
#define pb push_back
#define fi first
#define se second
#define int long long
#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < (int)v.size(); i++) { cout << v[i]; if(i != (int)v.size() - 1) cout << endl; }; return os; }
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

//const int mod = 1000000007;
const int mod = 998244353;

v_Pii decompose(vec a, int m){
    int n = SZ(a);
    v_Pii p;
    REP(i, n){
        Pii q0 = Pii(a[i], 1);
        while(q0.fi % m == 0){
            q0.fi /= m;
            q0.se *= m;
        }
        if(SZ(p) > 0 && p.back().fi == q0.fi){
            p.back().se += q0.se;
        }else{
            p.pb(q0);
        }
    }
    return p;
}

signed main(){

    int t; cin >> t;
    REP(_, t){
        int n, m; cin >> n >> m;
        vec a(n); cin >> a;
        int k; cin >> k;
        vec b(k); cin >> b;

        auto a0 = decompose(a, m), b0 = decompose(b, m);
        //vdebug(a0); vdebug(b0);

        bool f = false;
        if(SZ(a0) == SZ(b0)){
            f = true;
            REP(i, SZ(a0)) if(a0[i] != b0[i]) f = false;
        }
        chOut(f, "Yes", "No");
    }

    return 0;
}