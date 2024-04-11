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
#define int long long
#define INF 4000000000000000000
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
using Pdi = pair<double, int>;
using bools = vector<bool>;
using pairs = vector<Pii>;

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

const int mod = 1000000007;
//const int mod = 998244353;
//#define Add(x, y) x = (x + (y)) % mod
//#define Mult(x, y) x = (x * (y)) % mod

//f(b+1)-f(b)
int df(int a, int b){
    if(b == a) return -INF;

    return a - 3 * b * b - 3 * b - 1;
}

signed main(){

    int n, k; cin >> n >> k;
    vec a(n); cin >> a;

    vec ans0(n), ans1(n);

    int d0 = -INF, d1 = INF;
    while(d1 - d0 > 1){
        int d = (d0 + d1) / 2;
        int cnt = 0;

        REP(i, n){
            int b0 = -1, b1 = a[i];
            while(b1 - b0 > 1){
                int b = (b0 + b1) / 2;
                if(df(a[i], b) < d) b1 = b;
                else b0 = b;
            }
            cnt += b1;
        }

        if(cnt >= k) d0 = d;
        else d1 = d;  
    }
    //debug(d0); debug(d1);

    REP(i, n){
        int b0 = -1, b1 = a[i];
        while(b1 - b0 > 1){
            int b = (b0 + b1) / 2;
            if(df(a[i], b) < d0) b1 = b;
            else b0 = b;
        }
        ans0[i] = b1;

        b0 = -1, b1 = a[i];
        while(b1 - b0 > 1){
            int b = (b0 + b1) / 2;
            if(df(a[i], b) < d1) b1 = b;
            else b0 = b;
        }
        ans1[i] = b1;
    }

    int S = 0;
    REP(i, n) S += ans1[i];
    REP(i, n){
        int d = min(k - S, ans0[i] - ans1[i]);
        ans1[i] += d;
        S += d;
    }
    REP(i, n) cout << ans1[i] << " ";
    cout << endl;

    return 0;
}