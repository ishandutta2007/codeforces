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

int seed = 0, base = 0;
int rnd(){
    int ret = seed;
    seed = (seed * base + 233) % mod;
    return ret;
}

int calcans(vec ans){
    int x = 1;
    REP(i, SZ(ans)){
        int y = ans[i] ^ ((i + 1) * (i + 1));
        y %= mod;
        (x *= y + 1) %= mod;
        if(x < 0){
            break;
        }
    }
    return x;
}

signed main(){

    int n, m; cin >> n >> m;
    vec p(m + 1), k(m + 1), b(m + 1), w(m + 1);
    FOR(i, 1, m + 1){
        cin >> p[i] >> k[i] >> b[i] >> w[i];
    }
    p[0] = 0;
    vec a(n), t(n);
    FOR(i, 1, m + 1){
        seed = b[i];
        base = w[i];
        FOR(j, p[i - 1], p[i]){
            t[j] = rnd() % 2;
            a[j] = (rnd() % k[i]) + 1;
        }
    }
    
    int S = 0;
    REP(i, n){
        if(t[i] == 0) S += a[i];
        else S -= a[i];
    }
    if(S < 0){
        REP(i, n) t[i] ^= 1;
        S *= -1;
    }
    //vdebug(a); vdebug(t);

    vec ans(n, 0);
    if(S == 0){
        REP(i, n) ans[i] = a[i];
    }else{
        int i0 = 0;
        if(t[0] == 0){
            ans[0] = 1;
            a[0]--;
            i0 = -1;
            REP(i, n) if(t[i] == 1){
                i0 = i;
                break;
            }
            if(i0 == -1){
                Out(calcans(ans));
                return 0;
            }
        }

        int T = 0;
        REP(i, 2 * n){
            int j = (i0 + i) % n;
            if(t[j] == 1){
                ans[j] += a[j];
                T += a[j];
                a[j] = 0;
            }else{
                int x = min(a[j], T);
                ans[j] += x;
                T -= x;
                a[j] -= x;
            }
        }
    }
    //vdebug(ans);
    
    Out(calcans(ans));

    return 0;
}