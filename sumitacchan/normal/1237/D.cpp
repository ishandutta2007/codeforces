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
#define vdebug(v) cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl;
#define mdebug(m) cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;}
#define pb push_back
#define f first
#define s second
//#define int long long
//#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < v.size(); i++) { cout << v[i]; if(i != v.size() - 1) cout << endl; }; return os; }
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

struct SparseTable
{
    using T = int;
    vector<vector<T>> table;

    T F(T a, T b){
        return min(a, b);
    }
    
    SparseTable(int N){
        int n = 32 - __builtin_clz((signed)N);
        table = vector<vector<T>>(n, vector<T>(N));
    }

    SparseTable(int N, vector<T> &A){
        int n = 32 - __builtin_clz((signed)N);
        table = vector<vector<T>>(n, vector<T>(N));
        initialize(A);
    }

    SparseTable(){}

    void initialize(vector<T> &A){
        for(int i = 0; i < A.size(); i++) table[0][i] = A[i];
        for(int n = 0; n < table.size() - 1; n++){
            for(int i = 1 << n; i < A.size(); i++){
                table[n + 1][i - (1 << n)] = F(table[n][i - (1 << n)], table[n][i]);
            }
        }
    }

    // the range is [l, r]
    // 0 <= l <= r < N must be satisfied
    T get(int l, int r){
        int n = 31 - __builtin_clz((signed)(r - l + 1));
        return F(table[n][l], table[n][r - (1 << n) + 1]);
    }

};

signed main(){

    int n; cin >> n;
    vec a(n); cin >> a;
    int M = a[0], m = a[0];
    REP(i, n){
        Max(M, a[i]);
        Min(m, a[i]);
    }
    if(2 * m >= M){
        REP(i, n) cout << -1 << ' ';
        cout << endl;
        return 0;
    }

    REP(i, n) a.pb(a[i]);
    SparseTable ST(2 * n, a);

    pairs p(n);
    REP(i, n) p[i] = Pii(a[i], i);
    Sort(p); Reverse(p);

    vec ans(n, -1);
    set<int> s;
    REP(i, n){
        int i0 = p[i].s;
        if(SZ(s)){
            int j = *(s.lower_bound(i0));
            if(2 * ST.get(i0, j) >= a[i0]){
                ans[i0] = ans[j % n] + j - i0;
            }
        }
        if(ans[i0] == -1){
            int j0 = i0, j1 = i0 + n;
            while(j1 - j0 > 1){
                int jm = (j0 + j1) / 2;
                if(2 * ST.get(i0, jm) >= a[i0]) j0 = jm;
                else j1 = jm;
            }
            ans[i0] = j1 - i0;
        }
        s.insert(i0);
        s.insert(i0 + n);
    }

    REP(i, n) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}