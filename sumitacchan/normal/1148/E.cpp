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
template<typename T> void Out(T x) { cout << x << '\n'; }
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
#define Add(x, y) x = (x + (y)) % mod
#define Mult(x, y) x = (x * (y)) % mod



signed main(){

    int n; cin >> n;
    vec s(n); cin >> s;
    pairs S(n);
    REP(i, n) S[i] = Pii(s[i], i);
    Sort(S); Sort(s);
    vec t(n); cin >> t; Sort(t);

    int c = 0;
    REP(i, n) c += s[i] - t[i];
    if(c != 0){
        Out("NO");
        return 0;
    }

    pairs p, m;
    REP(i, n){
        int d = t[i] - s[i];
        if(d > 0) p.pb(Pii(i, d));
        else if(d < 0) m.pb(Pii(i, -d));
    }
    vector<PPi> ans;

    if(SZ(p) == 0 && SZ(m) == 0){
        Out("YES");
        Out(0);
        return 0;
    }

    int i0 = 0, j0 = 0;
    while(i0 < SZ(p) && j0 < SZ(m)){
        if(t[p[i0].f] - p[i0].s >= t[m[j0].f] + m[j0].s){
            Out("NO");
            return 0;
        }
        int d = min(p[i0].s, m[j0].s);
        p[i0].s -= d;
        m[j0].s -= d;
        ans.pb(PPi(Pii(S[p[i0].f].s, S[m[j0].f].s), d));
        if(p[i0].s == 0) i0++;
        if(m[j0].s == 0) j0++;
    }
    Out("YES");
    Out(SZ(ans));
    REP(i, SZ(ans)){
        cout << ans[i].f.f + 1 << " " << ans[i].f.s + 1 << " " << ans[i].s << '\n';
    }

    return 0;
}