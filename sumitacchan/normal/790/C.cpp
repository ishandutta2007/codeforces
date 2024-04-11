#include <bits/stdc++.h>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using gpp_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename L> using gpp_map = tree<T, L, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using gpp_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;*/
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
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define bit(n) (1LL<<(n))
#define bit_exist(x, n) ((x >> n) & 1)
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) { cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl; }
#define mdebug(m) { cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;} }
#define Return(ans) { cout << (ans) << endl; return 0; }
#define pb push_back
#define f first
#define s second
//#define int long long
#define INF 100000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < v.size(); i++) { cout << v[i]; if(i != v.size() - 1) cout << endl; }; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p){ cout << '(' << p.first << ',' << p.second << ')'; return os; }
template<typename T> void Out(T x) { cout << x << endl; }
template<typename T1, typename T2> void Ans(bool f, T1 y, T2 n) { if(f) Out(y); else Out(n); }

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;
using bools = vector<bool>;
using pairs = vector<Pii>;

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

const int mod = 1000000007;
//const int mod = 998244353;
//#define Add(x, y) x = (x + (y)) % mod
//#define Mult(x, y) x = (x * (y)) % mod



signed main(){

    int n; cin >> n;
    string s; cin >> s;

    vec v, k, o;
    REP(i, n){
        if(s[i] == 'V') v.pb(i);
        else if(s[i] == 'K') k.pb(i);
        else o.pb(i);
    }

    int nv = SZ(v), nk = SZ(k), no = SZ(o);
    int dp[76][76][76][2];
    REP(a, nv + 1) REP(b, nk + 1) REP(c, no + 1) REP(d, 2) dp[a][b][c][d] = INF;
    dp[0][0][0][0] = 0;

    vec cv(n + 1, 0), ck(n + 1, 0), co(n + 1, 0);
    REP(i, n + 1){
        REP(j, i){
            if(s[j] == 'V') cv[i]++;
            else if(s[j] == 'K') ck[i]++;
            else co[i]++;
        }
    }
    //vdebug(cv); vdebug(ck); vdebug(co);

    REP(a, nv + 1) REP(b, nk + 1) REP(c, no + 1){
        if(a < nv){
            int i0 = v[a];
            REP(d, 2) Min(dp[a + 1][b][c][1], dp[a][b][c][d] + max(0, ck[i0] - b) + max(0, co[i0] - c));
        }
        if(b < nk){
            int i0 = k[b];
            Min(dp[a][b + 1][c][0], dp[a][b][c][0] + max(0, cv[i0] - a) + max(0, co[i0] - c));
        }
        if(c < no){
            int i0 = o[c];
            REP(d, 2) Min(dp[a][b][c + 1][0], dp[a][b][c][d] + max(0, cv[i0] - a) + max(0, ck[i0] - b));
        }
    }
    int ans = min(dp[nv][nk][no][0], dp[nv][nk][no][1]);
    Out(ans);

    return 0;
}