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
#define INF 100000000
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

vector<bools> check1(vector<string> &s, int n, int m){
    vector<bools> ok(n, bools(m, false));
    ok[0][0] = true;
    REP(i, n) REP(j, m) if(ok[i][j]){
        if(i < n - 1 && s[i + 1][j] == '.') ok[i + 1][j] = true;
        if(j < m - 1 && s[i][j + 1] == '.') ok[i][j + 1] = true;
    }
    return ok;
}

vector<bools> check2(vector<string> &s, int n, int m){
    vector<bools> ok(n, bools(m, false));
    ok[n - 1][m - 1] = true;
    IREP(i, n) IREP(j, m) if(ok[i][j]){
        if(i > 0 && s[i - 1][j] == '.') ok[i - 1][j] = true;
        if(j > 0 && s[i][j - 1] == '.') ok[i][j - 1] = true;
    }
    return ok;
}

signed main(){

    int n, m; cin >> n >> m;
    vector<string> s(n); cin >> s;

    vector<bools> ok1 = check1(s, n, m), ok2 = check2(s, n, m);
    if(!ok1[n - 1][m - 1]) Out(0);
    else{
        bool f = false;
        vec cnt(n + m, 0);
        REP(i, n) REP(j, m) if(ok1[i][j] && ok2[i][j]) cnt[i + j]++;
        FOR(d, 1, n + m - 2) if(cnt[d] < 2) f = true;
        if(f) Out(1);
        else Out(2);
    }

    return 0;
}