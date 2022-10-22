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

int s2i(string s){
    int v = 0;
    REP(i, SZ(s)) if(s[i] == '1') v += bit(i);
    return v;
}

uint32_t xorshift(){
    static uint32_t x = 2463534242;
    x ^= (x << 13);
    x ^= (x >> 17);
    x ^= (x << 5);
    return x;
}

signed main(){

    int n, m, p; cin >> n >> m >> p;
    vector<string> s(n); cin >> s;
    vec t(n);
    REP(i, n) t[i] = s2i(s[i]);

    int MM = 0, ans = 0;
    REP(_, 20){
        int mask = t[xorshift() % n];
        vec v;
        REP(i, m) if((mask >> i) & 1) v.pb(i);

        int sz = SZ(v);
        if(sz == 0) continue;

        vec dp(bit(sz), 0);
        REP(i, n){
            int x = 0;
            REP(k, sz) if((t[i] >> v[k]) & 1){
                x ^= bit(k);
            }
            dp[x]++;
        }

        REP(k, sz){
            REP(x, bit(sz)){
                if((x >> k) & 1) dp[x ^ bit(k)] += dp[x];
            }
        }
        
        REP(x, bit(sz)) if(dp[x] >= (n + 1) / 2){
            if(MM >= __builtin_popcountll(x)) continue;
            MM = __builtin_popcountll(x);
            ans = 0;
            REP(k, sz) if((x >> k) & 1) ans ^= bit(v[k]);
        }
    }


    string res(m, '0');
    REP(i, m) if((ans >> i) & 1) res[i] = '1';
    cout << res << endl;

    return 0;
}