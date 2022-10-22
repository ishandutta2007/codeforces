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

void imp(){
    Out("No");
    exit(0);
}

bool check(mat &s, int j0, int j1, Pii &res, vec ne){
    int n = SZ(s);
    Pii tmp = Pii(-1, -1);
    vec v;
    FOR(i, 1, n){
        if(s[i][j0] != s[0][j0]) ne[i]--;
        if(s[i][j1] != s[0][j1]) ne[i]--;

        if(ne[i] >= 3) return false;
        else if(ne[i] == 2) tmp = Pii(s[i][j0], s[i][j1]);
        else if(ne[i] == 1) v.pb(i);
    }

    if(tmp.fi != -1){
        FOR(i, 1, n){
            int m = ne[i];
            if(s[i][j0] != tmp.fi) m++;
            if(s[i][j1] != tmp.se) m++;
            if(m > 2) return false;
        }
        res = tmp;
        return true;
    }else if(SZ(v) >= 1){
        Pii tmp = Pii(s[v[0]][j0], -1);
        bool ok = true;
        for(int i: v) if(s[i][j0] != tmp.fi){
            if(tmp.se == -1) tmp.se = s[i][j1];
            else if(tmp.se != s[i][j1]) ok = false;
        }
        if(ok){
            if(tmp.se == -1) tmp.se = s[0][j1];
            res = tmp;
            return true;
        }

        tmp = Pii(-1, s[v[0]][j1]);
        ok = true;
        for(int i: v) if(s[i][j1] != tmp.se){
            if(tmp.fi == -1) tmp.fi = s[i][j0];
            else if(tmp.fi != s[i][j0]) ok = false;
        }
        if(ok){
            if(tmp.fi == -1) tmp.se = s[0][j0];
            res = tmp;
            return true;
        }

        return false;
    }else{
        res = Pii(s[0][j0], s[0][j1]);
        return true;
    }

}

signed main(){

    int n, m; cin >> n >> m;
    mat s(n, vec(m)); cin >> s;

    vec v0;
    vec ne(n);
    FOR(i, 1, n){
        vec v;
        REP(j, m) if(s[i][j] != s[0][j]){
            v.pb(j);
            ne[i]++;
        }
        if(SZ(v) >= 5) imp();
        else if(SZ(v) > SZ(v0)) v0.swap(v);
    }

    vec ans;
    if(SZ(v0) <= 2){
        ans = s[0];
    }else if(SZ(v0) == 3){
        Pii res;
        bool ok = false;
        REP(i, 3) REP(j, m) if(v0[i] != j){
            if(!ok && check(s, v0[i], j, res, ne)){
                ans = s[0];
                ans[v0[i]] = res.fi;
                ans[j] = res.se;
                ok = true;
                break;
            }
        }
        if(!ok) imp();
    }else if(SZ(v0) == 4){
        Pii res;
        bool ok = false;
        REP(i, 4) FOR(j, i + 1, 4) {
            if(ok) break;
            if(!ok && check(s, v0[i], v0[j], res, ne)){
                ans = s[0];
                ans[v0[i]] = res.fi;
                ans[v0[j]] = res.se;
                ok = true;
                break;
            }
        }
        if(!ok) imp();
    }

    Out("Yes");
    REP(i, m) cout << ans[i] << " ";
    cout << endl;

    return 0;
}