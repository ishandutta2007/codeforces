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

//int M0, T;
bool ask(int X){
    cout << "? " << X << endl;
    string res; cin >> res;
    return (res == "Lucky!");

    /*T++;
    return X <= M0;*/
}

signed main(){

    const int M = 100000000000000;
    const int n = 50;
    mat dp(n + 1, vec(n + 1, 0));
    dp[0][0] = 1;
    FOR(i, 1, n + 1){
        REP(j, i + 1){
            if(j - 1 >= 0) dp[i][j] += dp[i - 1][j - 1];
            dp[i][j] += dp[i - 1][min(j + 1, i - 1)];
        }
    }
    //debug(dp[n][0]);

    int t; cin >> t;
    REP(_, t){
        //T = 0; cin >> M0;
        int R = 1;
        int m0 = 0, m1 = M + 1;
        REP(i, 60){
            int X = bit(i);
            if(X >= m1) break;
            if(ask(X)){
                R += X;
                m0 = X;
            }else{
                R -= X;
                m1 = X;
            }
        }
        ask(m0);
        R += m0;

        int n0 = n, y = 0;
        while(m1 - m0 > 1){
            if(y == 0){
                ask(m0);
                R += m0;
                y++;
            }else{
                int m = min(m0 + dp[n0 - 1][min(y - 1, n0 - 1)], (m0 + m1) / 2);
                while(R < m){
                    ask(m0);
                    R += m0;
                }
                if(ask(m)){
                    y++;
                    R += m;
                    m0 = m;
                }else{
                    y--;
                    R -= m;
                    m1 = m;
                }
            }
            n0--;
        }

        cout << "! " << m0 << endl;
    }

    return 0;
}