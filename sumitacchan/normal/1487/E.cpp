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
//#define int long long
//#define INF 1000000000000000000
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

const int INF = 1000000000;

signed main(){

    vec n(4); cin >> n;
    mat a(4);
    REP(i, 4){
        a[i].resize(n[i]);
        cin >> a[i];
    }
    vec m(3);
    vector<v_Pii> P(3);
    REP(i, 3){
        cin >> m[i];
        P[i].resize(m[i]);
        REP(j, m[i]){
            cin >> P[i][j].fi >> P[i][j].se;
            P[i][j].fi--; P[i][j].se--;
        }
    }

    v_Pii A0(n[0]);
    REP(i, n[0]) A0[i] = Pii(a[0][i], i);
    Sort(A0);
    vector<set<int>> s10(n[1]);
    for(auto q: P[0]) s10[q.se].insert(q.fi);
    REP(i, n[1]){
        bool ok = false;
        REP(j, n[0]) if(s10[i].count(A0[j].se) == 0){
            a[1][i] += A0[j].fi;
            ok = true;
            break;
        }
        if(!ok) a[1][i] = INF;
    }

    v_Pii A3(n[3]);
    REP(i, n[3]) A3[i] = Pii(a[3][i], i);
    Sort(A3);
    vector<set<int>> s23(n[2]);
    for(auto q: P[2]) s23[q.fi].insert(q.se);
    REP(i, n[2]){
        bool ok = false;
        REP(j, n[3]) if(s23[i].count(A3[j].se) == 0){
            a[2][i] += A3[j].fi;
            ok = true;
            break;
        }
        if(!ok) a[2][i] = INF;
    }
    

    v_Pii A2(n[2]);
    REP(i, n[2]) A2[i] = Pii(a[2][i], i);
    Sort(A2);
    vector<set<int>> s12(n[1]);
    for(auto q: P[1]) s12[q.fi].insert(q.se);
    int ans = INF;
    REP(i, n[1]) if(a[1][i] < INF){
        bool ok = false;
        REP(j, n[2]) if(s12[i].count(A2[j].se) == 0){
            if(A2[j].fi < INF) chmin(ans, a[1][i] + A2[j].fi);  
            break;
        }
    }
    chOut(ans < INF, ans, -1);

    return 0;
}