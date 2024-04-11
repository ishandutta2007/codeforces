//Optimization
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx")

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



signed main(){

    int k; cin >> k;
    vec F(6); cin >> F;
    int q; cin >> q;
    vec n(q); cin >> n;

    const int MM = 1000000;
    vec dp(MM, -INF);
    dp[0] = 0;

    int t = 1;
    REP(d, 6){
        vec ws, vs;
        int k0 = k - 2, sz = 1;
        while(k0 >= sz){
            ws.pb(9 * t * sz);
            vs.pb(F[d] * 3 * sz);
            k0 -= sz;
            sz *= 2;
        }
        if(k0 > 0){
            ws.pb(9 * t * k0);
            vs.pb(F[d] * 3 * k0);
        }

        REP(i, SZ(ws)){
            IFOR(j, ws[i], MM) chmax(dp[j], dp[j - ws[i]] + vs[i]); 
        }

        REP(_, min(k, 2LL)){
            IFOR(j, 0, MM){
                REP(i, 10){
                    int add = 0;
                    if(i % 3 == 0) add = F[d] * i / 3;
                    if(j >= i * t) chmax(dp[j], dp[j - i * t] + add); 
                }
            }
        }

        t *= 10;
    }

    REP(i, q){
        cout << dp[n[i]] << '\n';
    }



    return 0;
}