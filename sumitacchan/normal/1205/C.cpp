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
#define int long long
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

int dx[3] = {2, 0, 1};
int dy[3] = {0, 2, 1};

signed main(){

    int n; cin >> n;
    mat ans(n, vec(n, -1));
    ans[0][0] = 1;
    ans[n - 1][n - 1] = 0;
    ans[0][1] = 1; //temporary

    int res;

    REP(i, n) REP(j, n) if(ans[i][j] != -1){
        REP(k, 3){
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < n && y >= 0 && y < n && ans[x][y] == -1){
                cout << "? " << i + 1 << " " << j + 1 << " " << x + 1 << " " << y + 1 << endl;
                cin >> res;
                if(res == 1) ans[x][y] = ans[i][j];
                else ans[x][y] = 1 - ans[i][j];
            }
        }
    }
    
    REP(i, n) if(ans[i][0] == -1){
        cout << "? " << i + 1 << " " << 1 << " " << i + 1 << " " << 3 << endl;
        cin >> res;
        if(res == 1) ans[i][0] = ans[i][2];
        else ans[i][0] = 1 - ans[i][2];
    }

    vec v;
    REP(i, n) v.pb(ans[0][i]);
    FOR(i, 1, n) v.pb(ans[i][n - 1]);
    int i0 = 0;
    REP(i, SZ(v) - 3){
        if((v[i] ^ v[i + 2]) == (v[i + 1] ^ v[i + 3])){
            i0 = i;
            break;
        }
    }
    int x0, y0, x1, y1;
    if(i0 < n){
        x0 = 0, y0 = i0;
    }else{
        x0 = i0 - (n - 1), y0 = n - 1;
    }
    i0 += 3;
    if(i0 < n){
        x1 = 0, y1 = i0;
    }else{
        x1 = i0 - (n - 1), y1 = n - 1;
    }
    cout << "? " << x0 + 1 << " " << y0 + 1 << " " << x1 + 1 << " " << y1 + 1 << endl;
    cin >> res;
    bool flip;
    if(res == 1){
        if(ans[x0][y0] != ans[x1][y1]) flip = true;
        else flip = false;
    }else{
        if(ans[x0][y0] == ans[x1][y1]) flip = true;
        else flip = false;
    }
    if(flip){
        REP(i, n) REP(j, n) if((i + j) % 2) ans[i][j] = 1 - ans[i][j];
    }

    cout << "!" << endl;
    REP(i, n){
        REP(j, n) cout << ans[i][j];
        cout << endl;
    }

    return 0;
}