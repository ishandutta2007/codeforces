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

bool is_in(int x, Pii r){
    return (r.fi <= x && x <= r.se);
}

signed main(){

    int n, m; cin >> n >> m;
    vec k(n);
    v_Pii r0(n), r1(n);
    REP(i, n){
        cin >> k[i];
        cin >> r0[i].fi >> r0[i].se;
        cin >> r1[i].fi >> r1[i].se;
    }

    set<Pii> dp0, dp1;
    if(is_in(k[0], r0[0]) && is_in(0, r1[0])) dp1.insert(Pii(0, -1));
    if(is_in(k[0], r1[0]) && is_in(0, r0[0])) dp0.insert(Pii(0, -1));

    map<Pii, Pii> prev;

    FOR(i, 1, n){
        int last0 = -2, last1 = -2;
        if(SZ(dp0)) last0 = (*dp0.begin()).se;
        if(SZ(dp1)) last1 = (*dp1.begin()).se;
        
        if(is_in(k[i], r0[i])){
            while(SZ(dp1)){
                auto it = dp1.begin();
                if((*it).fi < r1[i].fi) dp1.erase(it);
                else break;
            }
            while(SZ(dp1)){
                auto it = dp1.end(); it--;
                if((*it).fi > r1[i].se) dp1.erase(it);
                else break;
            }
        }else dp1.erase(all(dp1));

        if(is_in(k[i], r1[i])){
            while(SZ(dp0)){
                auto it = dp0.begin();
                if((*it).fi < r0[i].fi) dp0.erase(it);
                else break;
            }
            while(SZ(dp0)){
                auto it = dp0.end(); it--;
                if((*it).fi > r0[i].se) dp0.erase(it);
                else break;
            }
        }else dp0.erase(all(dp0));

        if(last0 >= -1 && is_in(k[i], r0[i]) && is_in(k[i - 1], r1[i])){
            dp1.insert(Pii(k[i - 1], i - 1));
            prev[Pii(i, i - 1)] = Pii(last0, last0 + 1);
        }
        if(last1 >= -1 && is_in(k[i], r1[i]) && is_in(k[i - 1], r0[i])){
            dp0.insert(Pii(k[i - 1], i - 1));
            prev[Pii(i - 1, i)] = Pii(last1 + 1, last1);
        }
    }

    if(SZ(dp0) == 0 && SZ(dp1) == 0){
        Out("No");
        return 0;
    }

    vec ans(n);
    Pii now;
    if(SZ(dp0) > 0) now = Pii((*dp0.begin()).se, n - 1);
    else now = Pii(n - 1, (*dp1.begin()).se);

    while(true){
        if(now.fi < now.se) ans[now.se] = 1;
        else ans[now.fi] = 0;

        if(max(now.fi, now.se) == 0) break;

        if(llabs(now.fi - now.se) > 1){
            if(now.fi > now.se) now.fi--;
            else now.se--;
        }else{
            if(now.fi > now.se){
                Pii next = prev[now];
                FOR(i, next.se + 1, now.se + 1) ans[i] = 1;
                now = next;
            }else{
                Pii next = prev[now];
                FOR(i, next.fi + 1, now.fi + 1) ans[i] = 0;
                now = next;
            }
        }
    }

    Out("Yes");
    for(int x: ans) cout << x << ' ';
    cout << endl;

    return 0;
}