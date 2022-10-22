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
#define INF 1000000000000000000
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



signed main(){

    int N; cin >> N;
    vector<string> A(N), B(N);
    cin >> A;
    cin >> B;
    mat X(N, vec(N, 0));
    REP(i, N) REP(j, N) if(A[i][j] != B[i][j]) X[i][j] = 1;

    string C; cin >> C;
    vec s(N, 0);
    REP(i, N) if(C[i] == '1') s[i] = 1;

    int i0 = -1;
    REP(i, N) if(s[i] == 1){
        i0 = i;
        break;
    }
    if(i0 == -1){
        int cnt = 0;
        REP(i, N) REP(j, N) cnt += X[i][j];
        if(cnt) Out(-1);
        else Out(0);
        return 0;
    }

    REP(_, 2){
        vec r, h;
        mat X0 = X;
        if(_ == 1){
            r.pb(i0);
            REP(j, N) if(s[j]) X[i0][j] = 1 - X[i0][j];
        }
        REP(j, N) if(X[i0][j]){
            h.pb(j);
            REP(i, N) if(s[i]) X[i][j] = 1 - X[i][j];
        }
        REP(i, N) if(i != i0 && X[i][i0]){
            r.pb(i);
            REP(j, N) if(s[j]) X[i][j] = 1 - X[i][j];
        }
        int cnt = 0;
        REP(i, N) REP(j, N) cnt += X[i][j];
        if(cnt == 0){
            Out(SZ(r) + SZ(h));
            for(int i: r) cout << "row " << i << '\n';
            for(int i: h) cout << "col " << i << '\n'; 
            return 0;
        }
    }
    Out(-1);

    return 0;
}