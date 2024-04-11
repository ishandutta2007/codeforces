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
//#define int long long
//#define INF 1000000000000000000
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

const int INF = 1000000000;

signed main(){

    int n; cin >> n;
    vec x(n), y(n), c(n);
    REP(i, n){
        cin >> x[i] >> y[i] >> c[i];
        c[i]--;
    }

    int ans1 = 0;
    REP(r, 4){
        vec X(n), Y(n);
        REP(i, n){
            X[i] = x[i]; Y[i] = y[i];
            if((r >> 1) & 1) swap(X[i], Y[i]);
            if(r & 1) Y[i] *= -1;
        }

        vec p({0, 1, 2});
        do{
            int k0 = p[0], k1 = p[1], k2 = p[2];
            
            vec y0;
            v_Pii xy1, xy2;
            REP(i, n){
                if(c[i] == k0) y0.pb(Y[i]);
                if(c[i] == k1) xy1.pb(Pii(X[i], Y[i]));
                if(c[i] == k2) xy2.pb(Pii(X[i], Y[i]));
            }
            Sort(y0);
            Sort(xy1);
            Sort(xy2);

            int ok = 0, ng = n / 3 + 1;
            while(ng - ok > 1){
                int mid = (ng + ok) / 2;
                int Yth = y0[mid - 1];

                int Xl = INF, Xr = -INF;
                int cntl = 0, cntr = 0;
                REP(i, n / 3) if(xy1[i].se > Yth){
                    cntl++;
                    if(cntl == mid){
                        Xl = xy1[i].fi;
                        break;
                    }
                }
                IREP(i, n / 3) if(xy2[i].se > Yth){
                    cntr++;
                    if(cntr == mid){
                        Xr = xy2[i].fi;
                        break;
                    }
                }
                //debug(Yth); debug(Xl); debug(Xr);

                if(Xl < Xr) ok = mid;
                else ng = mid;
            }

            chmax(ans1, ok);

        } while(next_permutation(all(p)));
    }

    int ans2 = 0;
    REP(r, 2){
        vec p({0, 1, 2});
        do{
            mat X(3);
            REP(i, n){
                int xx = (r == 0 ? x[i] : y[i]);
                X[p[c[i]]].pb(xx);
            }
            REP(k, 3) Sort(X[k]);

            REP(i, n / 3){
                if(Lower_bound(X[1], X[2][n / 3 - 1 - i]) - Upper_bound(X[1], X[0][i]) >= i + 1){
                    chmax(ans2, i + 1);
                }
            }

        } while(next_permutation(all(p)));

    }

    Out(max(ans1, ans2) * 3);

    return 0;
}