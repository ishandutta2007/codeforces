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

void valswap(vec &c, vec &inv, int x, int y, v_Pii &ans){
    c[inv[x]] = y;
    c[inv[y]] = x;
    ans.pb(Pii(inv[x], inv[y]));
    swap(inv[x], inv[y]);
}

signed main(){

    int n; cin >> n;
    vec c(n); cin >> c;
    REP(i, n) c[i]--;
    vec inv(n);
    REP(i, n) inv[c[i]] = i;

    mat P;
    v_bool used(n, false);    
    REP(i, n) if(!used[i]){
        int now = i;
        vec v;
        while(!used[now]){
            used[now] = true;
            v.pb(now);
            now = c[now];
        }
        P.pb(v);
    }

    int s = SZ(P);
    v_Pii ans;
    if(s == 1){
        vec v = P[0];
        valswap(c, inv, v[1], v[2], ans);
        valswap(c, inv, v[0], v[1], ans);
        
        vec w({v[0], v[2]});
        FOR(i, 3, n) w.pb(v[i]);
        w.pb(v[1]);

        FOR(i, 1, n - 1) valswap(c, inv, w[i], w[i + 1], ans);
        valswap(c, inv, w[0], w[n - 1], ans);
    }else{
        if(s % 2){
            P.pb(vec({P[0][0]}));
            s++;
        }

        REP(i, s / 2){
            vec v = P[2 * i], w = P[2 * i + 1];
            valswap(c, inv, v[0], w[0], ans);
            REP(i, SZ(v) - 1) valswap(c, inv, v[i], v[i + 1], ans);
            REP(i, SZ(w) - 1) valswap(c, inv, w[i], w[i + 1], ans);
            valswap(c, inv, v.back(), w.back(), ans);
        }
    }

    Out(SZ(ans));
    for(auto q: ans) cout << q.fi + 1 << ' ' << q.se + 1 << endl;

    return 0;
}