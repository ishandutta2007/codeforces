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

    int n; cin >> n;
    vec h(n); cin >> h;
    vector<unordered_set<int>> es(n);
    REP(i, n - 1){
        int a, b; cin >> a >> b;
        a--; b--;
        es[a].insert(b);
        es[b].insert(a);
    }

    int hmax = -1;
    REP(i, n) chmax(hmax, h[i]);

    vec deg(n), val(n);
    int ans = 0;
    priority_queue<Pii, vector<Pii>, greater<Pii>> que;
    REP(i, n){
        deg[i] = SZ(es[i]);
        if(deg[i] == 1){
            val[i] = h[i];
            ans += h[i];
            que.push(Pii(val[i], i));
        }
    }
    while(SZ(que) > 2){
        auto t = que.top(); que.pop();
        int v = t.se;
        int p = *(es[v].begin());
        es[p].erase(v);
        deg[p] = SZ(es[p]);
        if(deg[p] == 1){
            if(h[p] > val[v]) ans += h[p] - val[v];
            val[p] = max(h[p], val[v]);
            que.push(Pii(val[p], p));
        }
    }
    while(!que.empty()){
        auto t = que.top(); que.pop();
        int v = t.se;
        if(val[v] < hmax) ans += hmax - val[v];
    }

    Out(ans);

    return 0;
}