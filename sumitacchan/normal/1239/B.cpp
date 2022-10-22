#include <bits/stdc++.h>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using gpp_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename L> using gpp_map = tree<T, L, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using gpp_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;*/
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
    string s; cin >> s;

    vec c(n + 1);
    c[0] = 0;
    int now = 0, m = 0;
    REP(i, n){
        if(s[i] == '(') now++;
        else now--;
        c[i + 1] = now;
        Min(m, now);
    }
    if(now != 0){
        Out(0);
        Out("1 1");
        return 0;
    }
    //vdebug(c);
    int ans = 0;
    FOR(i, 1, n + 1) if(c[i] == m) ans++;
    Pii p(0, 0);

    int nm = ans;
    //() -> )(
    FOR(m0, m - 1, m + 1){
        int tmp = 0, i0;
        bool a = false;
        REP(i, n){
            if(!a){
                if(s[i] == '(' && c[i + 1] - 2 >= m0){
                    a = true;
                    i0 = i;
                    if(c[i + 1] - 2 == m0) tmp++;
                }
            }else{
                if(s[i] == ')'){
                    int t = tmp; if(m0 == m) t += nm;
                    if(t > ans){
                        ans = t; p = Pii(i0, i);
                    }
                }
                if(s[i] == ')' && c[i + 1] - 2 < m0){
                    a = false;
                    tmp = 0;
                }else if(c[i + 1] - 2 == m0) tmp++;
            }
        }
    }

    //)( -> ()
    FOR(m0, m + 1, m + 3){
        int l = INF, r = -1;
        REP(i, n) if(c[i + 1] < m0){
            Min(l, i);
            Max(r, i + 1);
        }
        if(0 <= l && r < n){
            swap(s[l], s[r]);
            int tmp = 0, now = 0;
            REP(i, n){
                if(s[i] == '(') now++;
                else now--;
                if(now < m0){
                    tmp = -INF;
                    break;
                }else if(now == m0) tmp++;
            }
            if(tmp > ans){
                ans = tmp;
                p = Pii(l, r);
            }
            swap(s[l], s[r]);
        }
    }
    

    cout << ans << endl;
    cout << p.f + 1 << ' ' << p.s + 1 << endl;

    return 0;
}