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

    int t; cin >> t;
    REP(q, t){
        int n; cin >> n;
        vec a(n); cin >> a;
        REP(i, n) a[i]--;

        mat ls(n);
        REP(i, n) ls[a[i]].pb(i);
        int k = 0;
        REP(i, n) if(SZ(ls[i]) > 0) k++;

        if(k == n - 1){
            int i0 = -1, i2 = -1;
            REP(i, n){
                if(SZ(ls[i]) == 0) i0 = i;
                if(SZ(ls[i]) == 2) i2 = i;
            }

            int x = ls[i2][0], y = ls[i2][1];
            if(x == i0){
                ls[i2].resize(0);
                ls[i2].pb(x);
            }else{
                ls[i2].resize(0);
                ls[i2].pb(y);
            }
        }

        v_bool fs(n, false), fr(n, false);
        vec b(n, -1);
        REP(i, n) if(SZ(ls[i]) > 0){
            fs[ls[i][0]] = true; fr[i] = true;
            b[ls[i][0]] = i;
        }

        vec vs, vr;
        REP(i, n){
            if(!fs[i] && !fr[i]){
                vs.pb(i); vr.pb(i);
                fs[i] = true; fr[i] = true;
            }
        }
        REP(i, n){
            if(!fs[i]) vs.pb(i);
            if(!fr[i]) vr.pb(i);
        }
        REP(i, SZ(vs)){
            b[vs[i]] = vr[(i + 1) % SZ(vs)];
        }

        cout << k << endl;
        REP(i, n) cout << b[i] + 1 << ' ';
        cout << '\n';
    }

    return 0;
}