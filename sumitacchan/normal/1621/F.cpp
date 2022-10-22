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
        int n, a, b, c; cin >> n >> a >> b >> c;
        string s; cin >> s;

        int ans = 0;

        REP(first, 2){

            vec p1;
            int n11 = 0;
            REP(i, n) if(s[i] == '1') p1.pb(i);
            REP(i, n - 1) if(s[i] == '1' && s[i + 1] == '1') n11++;

            int n0 = 0, m0 = 0;
            priority_queue<Pii, vector<Pii>, greater<Pii>> q00;
            if(SZ(p1) > 0){
                if(p1[0] == 1) m0++;
                else if(p1[0] > 1){
                    q00.push(Pii(1, p1[0] - 1));
                }
                if(n - 1 - p1.back() == 1) m0++;
                else if(n - 1 - p1.back() > 1){
                    q00.push(Pii(1, n - 2 - p1.back()));
                }
                REP(i, SZ(p1) - 1){
                    if(p1[i + 1] - p1[i] == 2) n0++;
                    else if(p1[i + 1] - p1[i] > 2){
                        q00.push(Pii(0, p1[i + 1] - p1[i] - 2));
                    }
                }
            }else if(n >= 2){
                q00.push(Pii(1, n - 1));
            }else if(n == 1){
                m0++;
            }

            int now = 0;
            int x = first;
            while(true){
                if(x == 0){
                    if(!q00.empty()){
                        chmax(ans, now + a);
                    } 
                    if(!q00.empty() && n11 > 0){
                        auto q = q00.top(); q00.pop();
                        //debug(q);
                        now += a;
                        chmax(ans, now);
                        q.se--;
                        if(q.se >= 1){
                            q00.push(q);
                        }else{
                            if(q.fi == 0) n0++;
                            else m0++;
                        }
                    }else if(n0 > 0){
                        now -= c;
                        chmax(ans, now);
                        n0--;
                        n11++;
                    }else if(m0 > 0){
                        now -= c;
                        chmax(ans, now);
                        m0--;
                    }else break;
                }else{
                    if(n11 > 0){
                        now += b;
                        n11--;
                        chmax(ans, now);
                    }else break;
                }
                x ^= 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}