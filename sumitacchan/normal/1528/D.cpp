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



signed main(){

    int n, m; cin >> n >> m;
    mat d(n, vec(n, INF));
    REP(i, m){
        int a, b, c; cin >> a >> b >> c;
        chmin(d[a][b], c);
    }

    mat ans(n, vec(n, INF));
    REP(s, n){
        vec dp(n, INF);
        int mm = INF;
        REP(i, n) chmin(mm, d[s][i]);
        mat st(n);
        REP(i, n) if(d[s][i] < mm + n){
            dp[i] = d[s][i];
            if(d[s][i] - mm < n) st[d[s][i] - mm].pb(i);
        }
        REP(t, n){
            while(SZ(st[t])){
                int v = st[t].back();
                st[t].pop_back();
                if(dp[v] < mm + t) continue;

                if(dp[(v + 1) % n] > dp[v] + 1 && t + 1 < n){
                    dp[(v + 1) % n] = dp[v] + 1;
                    st[t + 1].pb((v + 1) % n);
                }
                REP(i, n) if(d[v][i] < INF){
                    int j = (i + mm + t) % n;
                    if(dp[j] > dp[v] + d[v][i] && t + d[v][i] < n){
                        dp[j] = dp[v] + d[v][i];
                        st[t + d[v][i]].pb(j);
                    }
                }
            }
        }

        REP(i, n) ans[s][i] = dp[i];
        ans[s][s] = 0;
    }
    REP(i, n){
        REP(j, n) cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}