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

struct UnionFind
{
    vector<int> par, sz, mr;
    int n_cc;
    v_Pii range;

    UnionFind(int N){
        par = vector<int>(N);
        REP(i, N) par[i] = i;
        sz = vector<int>(N, 1);
        n_cc = N;

        mr = vec(N, N + 10);
        range.resize(N);
        REP(i, N) range[i] = Pii(i, i);
    }

    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;

        if(sz[x] < sz[y]) swap(x, y);

        par[y] = x;
        sz[x] += sz[y];
        n_cc--;

        chmin(mr[x], mr[y]);
        chmin(range[x].fi, range[y].fi);
        chmax(range[x].se, range[y].se);
    }

    bool is_union(int x, int y){
        x = find(x);
        y = find(y);
        return x == y;
    }

    int union_size(int x){
        return sz[find(x)];
    }

    int get_mr(int x){
        x = find(x);
        return mr[x];
    }

    Pii get_range(int x){
        x = find(x);
        return range[x];
    }

};


signed main(){

    int n, q; cin >> n >> q;
    set<int> st;
    REP(i, n) st.insert(i);
    v_bool used(n, false);
    UnionFind UF(n);

    REP(_, q){
        int t; cin >> t;
        if(t == 0){
            int l, r, x; cin >> l >> r >> x;
            l--; r--;
            if(x == 0){
                while(true){
                    auto it = st.lower_bound(l);
                    if(it != st.end() && (*it) <= r){
                        int i = *it;
                        used[i] = true;
                        if(i - 1 >= 0 && used[i - 1]) UF.unite(i, i - 1);
                        if(i + 1 < n  && used[i + 1]) UF.unite(i, i + 1);
                        st.erase(it);
                    }else break;
                }
            }else{
                int i = UF.find(l);
                chmin(UF.mr[i], r);
            }
        }else{
            int j; cin >> j;
            j--;

            string ans;
            if(used[j]) ans = "NO";
            else{
                int mr = UF.mr[j];
                if(j - 1 >= 0 && used[j - 1]){
                    chmin(mr, UF.get_mr(j - 1));
                }
                int Mr = j;
                if(j + 1 < n && used[j + 1]){
                    chmax(Mr, UF.get_range(j + 1).se);
                }
                if(mr <= Mr) ans = "YES";
                else ans = "N/A";
            }

            Out(ans);
        }
    }

    return 0;
}