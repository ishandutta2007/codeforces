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
#define INF 2000000000
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

    int n, k; cin >> n >> k;
    mat c(n, vec(n)); cin >> c;
    int ans = INF;

    vec a(k / 2 + 1, 0);
    int M = 1;
    REP(i, k / 2 - 1) M *= n;
    bools used(n + 1, false);
    used[0] = true;

    vector<vector<pairs>> mm(n, vector<pairs>(n, pairs(6, Pii(100000000 * 2 + 1, n))));
    REP(i, n) REP(j, n){
        pairs p;
        REP(l, n) if(i != l && j != l){
            p.pb(Pii(c[i][l] + c[l][j], l));
        }
        Sort(p);
        REP(l, min(SZ(p), 6)) mm[i][j][l] = p[l];
    }
    //mdebug(mm);

    REP(x, M){
        int x0 = x;
        REP(i, k / 2 - 1){
            a[i + 1] = x0 % n;
            x0 /= n;
            used[a[i + 1]] = true;
        }

        int tmp = 0;
        REP(i, k / 2){
            REP(l, 6){
                if(!used[mm[a[i]][a[i + 1]][l].s]){
                    tmp += mm[a[i]][a[i + 1]][l].f;
                    break;
                }
            }
        }
        Min(ans, tmp);

        REP(i, k / 2 - 1) if(a[i + 1]) used[a[i + 1]] = false;
    }
    Out(ans);

    return 0;
}