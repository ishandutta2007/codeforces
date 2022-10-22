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

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

const int mod = 1000000007;
//const int mod = 998244353;



signed main(){

    int n, m, k; cin >> n >> m >> k;
    vector<mat> cost(n, mat(m, vec(4, INF)));
    REP(i, n){
        REP(j, m - 1){
            int c; cin >> c;
            cost[i][j][1] = cost[i][j + 1][3] = c;
        }
    }
    REP(i, n - 1){
        REP(j, m){
            int c; cin >> c;
            cost[i][j][0] = cost[i + 1][j][2] = c;
        }
    }

    mat mincost(n, vec(m, INF));
    REP(i, n) REP(j, m){
        REP(d, 4) chmin(mincost[i][j], cost[i][j][d]);
    }

    if(k % 2){
        REP(i, n){
            REP(j, m) cout << -1 << " ";
            cout << endl;
        }
        return 0;
    }

    int l = k / 2;
    vector<mat> dp(l + 1, mat(n, vec(m, INF)));
    REP(i, n) REP(j, m) dp[0][i][j] = 0;
    REP(t, l){
        REP(i, n) REP(j, m){
            REP(d, 4) if(cost[i][j][d] < INF){
                int x = i + dx[d], y = j + dy[d];
                chmin(dp[t + 1][i][j], dp[t][x][y] + cost[i][j][d]);
            }
        }
    }

    REP(i, n){
        REP(j, m) cout << dp[l][i][j] * 2 << " ";
        cout << endl;
    }

    return 0;
}