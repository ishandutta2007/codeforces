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
#define vdebug(v) { cout << #v << "=" << endl; REP(i_debug, (int)v.size()){ cout << v[i_debug] << ","; } cout << endl; }
#define mdebug(m) { cout << #m << "=" << endl; REP(i_debug, (int)m.size()){ REP(j_debug, (int)m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;} }
#define pb push_back
#define fi first
#define se second
#define int long long
#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < (int)v.size(); i++) { cout << v[i]; if(i != (int)v.size() - 1) cout << endl; }; return os; }
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

//const int mod = 1000000007;
const int mod = 998244353;



signed main(){

    int t; cin >> t;
    REP(_, t){
        int n, m; cin >> n >> m;
        vec a0(n); cin >> a0;
        Sort(a0);
        vec a(m);
        REP(i, m) a[i] = a0[i + (n - m)];

        vec k(m), S(m);
        mat b(m);
        REP(i, m){
            cin >> k[i];
            b[i].resize(k[i]);
            cin >> b[i];
            REP(j, k[i]) S[i] += b[i][j];
        }
        v_Pii p(m);
        REP(i, m){
            p[i] = Pii((S[i] + k[i] - 1) / k[i], i);
        }
        Sort(p);
        vec pos(m);
        REP(i, m) pos[p[i].se] = i;

        vec ok_down(m + 1), ok(m + 1), ok_up(m + 1);
        REP(i, m){
            if(p[i].fi <= a[i]) ok[i + 1] = 1;
            if(i + 1 < m && p[i].fi <= a[i + 1]) ok_up[i + 1] = 1;
            if(i - 1 >= 0 && p[i].fi <= a[i - 1]) ok_down[i + 1] = 1;
        }
        REP(i, m){
            ok[i + 1] += ok[i];
            ok_up[i + 1] += ok_up[i];
            ok_down[i + 1] += ok_down[i];
        }
        //vdebug(ok);

        string ans = "";
        REP(i, m){
            int i0 = pos[i];
            REP(j, k[i]){
                int X = (S[i] - b[i][j] + k[i] - 2) / (k[i] - 1);
                int i1 = Lower_bound(p, Pii(X, i));
                if(i1 > i0) i1--;

                int f = 0;
                if(X <= a[i1]) f += 1;
                //[0,min(i0,i1))
                f += ok[min(i0, i1)] - ok[0];
                //(max(i0,i1),n-1]
                f += ok[m] - ok[max(i0, i1) + 1];
                if(i0 < i1){
                    //[i0+1,i1]
                    f += ok_down[i1 + 1] - ok_down[i0 + 1];
                }else if(i0 > i1){
                    //[i1,i0-1]
                    f += ok_up[i0] - ok_up[i1];
                }

                if(f == m) ans += '1';
                else ans += '0';
            }
        }
        cout << ans << endl;
    }


    return 0;
}