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
    REP(i, n) a[i]--;
    mat pos(n);
    REP(i, n) pos[a[i]].pb(i);
    
    int odd = -1;
    REP(i, n){
        if(SZ(pos[i]) % 2){
            if(odd == -1) odd = i;
            else{
                Out(0);
                return 0;
            }
        }
    }
    //debug(odd);
 
    int ans = 0;
    if(odd == -1){
        int L = INF, R = -INF;
        REP(i, n){
            int sz = SZ(pos[i]);
            if(sz){
                int l = pos[i][sz / 2 - 1], r = pos[i][sz / 2];
                //debug(l); debug(r);
                if(l >= n / 2) Max(R, l);
                if(r <= n / 2 - 1) Min(L, r);
            }
 
        }
        int d1 = -1, d2 = -1;
        REP(i, n / 2){
            if(a[i] != a[n - 1 - i]){
                d2 = i;
                if(d1 == -1) d1 = i;
            }
        }
        if(d1 == -1){
            ans = n * (n + 1) / 2;
        }else{
            REP(i, d1 + 1){
                if(i > L) break;
                int tmp = max(d2, R);
                ans += n - tmp;
            }
            FOR(i, d1 + 1,  n - 1 - d2 + 1){
                if(i > L) break;
                int tmp = max(n - 1 - d1, R);
                ans += n - tmp;
            }
        }
    }else{
        int L = INF, R = -INF;
        REP(i, n) if(i != odd){
            int sz = SZ(pos[i]);
            if(sz){
                int l = pos[i][sz / 2 - 1], r = pos[i][sz / 2];
                //debug(l); debug(r);
                if(l >= n / 2) Max(R, l);
                if(r <= n / 2) Min(L, r);
            }
 
        }
        int sz = SZ(pos[odd]);
        int c = pos[odd][sz / 2];
 
        if(c < n / 2){
            Min(L, c); Max(R, n / 2);
        }
        if(c > n / 2){
            Min(L, n / 2); Max(R, c);
        }
        //debug(L); debug(R);
 
        int d1 = -1, d2 = -1;
        REP(i, n / 2){
            if(a[i] != a[n - 1 - i]){
                d2 = i;
                if(d1 == -1) d1 = i;
            }
        }
        //debug(d1); debug(d2);
        if(d1 == -1){
            ans = n * (n + 1) / 2;
        }else{
            REP(i, d1 + 1){
                if(i > L) break;
                int tmp = max(d2, R);
                ans += n - tmp;
            }
            FOR(i, d1 + 1, n - 1 - d2 + 1){
                if(i > L) break;
                int tmp = max(n - 1 - d1, R);
                ans += n - tmp;
            }
        }
    }
    Out(ans);
 
    return 0;
}