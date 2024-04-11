#include <bits/stdc++.h>
using namespace std;
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



signed main(){

    int n; cin >> n;
    vec a(n); cin >> a;
    int win = a.back();

    vec v;
    int T = 0;
    REP(i, n) if(a[i] == win) T++;
    vec p(n + 1, 0);
    REP(i, n){
        if(a[i] == win) p[i + 1] = 1;
    }
    REP(i, n) p[i + 1] += p[i];

    pairs ans;
    FOR(t, 1, T + 1){
        int sw = 0, sl = 0;
        int l = 0;
        while(l < n){
            int qw = p[n] - p[l], ql = n - l - qw;
            if(max(qw, ql) < t){
                sw = -1;
                break;
            }
            int r0 = l, r1 = n;
            while(r1 - r0 > 1){
                int r = (r0 + r1) / 2;
                qw = p[r] - p[l], ql = r - l - qw;
                if(max(qw, ql) >= t) r1 = r;
                else r0 = r;
            }
            if(a[r1 - 1] == win) sw++;
            else sl++;
            l = r1;
        }
        if(sw == -1) continue;
        if(sw > sl) ans.pb(Pii(sw, t));
    }
    Sort(ans);
    cout << SZ(ans) << '\n';
    REP(i, SZ(ans)) cout << ans[i].f << ' ' << ans[i].s << '\n';


    return 0;
}