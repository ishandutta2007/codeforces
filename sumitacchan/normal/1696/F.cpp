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

template<typename T> 
struct edge{ int to; T cost; int id; };

template<typename T = long long>
struct Graph
{

    int N;
    vector<vector<edge<T>>> E;

    Graph(int N): N(N){
        E = vector<vector<edge<T>>>(N, vector<edge<T>>(0));
    }

    void add_Directed_edge(int from, int to, T cost = 1, int id = 0){
        E[from].push_back(edge<T>({ to, cost, id }));
    }

    void add_Undirected_edge(int v1, int v2, T cost = 1, int id = 0){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }

    void dfs(int v, vec &d, int p = -1){
        if(p == -1) d[v] = 0;
        else d[v] = d[p] + 1;
        for(auto e: E[v]) if(e.to != p) dfs(e.to, d, v);
    }

};

void solve(){
    int n; cin >> n;
    vector<vector<string>> s(n, vector<string>(n));
    REP(i, n){
        FOR(j, i + 1, n){
            cin >> s[i][j];
            s[j][i] = s[i][j];
        }
        s[i][i] = string(n, '1');
    }
    
    FOR(x, 1, n){
        v_bool used(n, false);
        queue<Pii> que;
        que.push(Pii(0, x));
        Graph G(n);
        G.add_Undirected_edge(0, x);
        used[0] = used[x] = true;
        while(!que.empty()){
            auto q = que.front(); que.pop();
            int u = q.fi, v = q.se;
            REP(w, n) if(!used[w]){
                Pii e0(-1, -1);
                if(s[u][w][v] == '1'){
                    e0 = Pii(v, w);
                }else if(s[v][w][u] == '1'){
                    e0 = Pii(u, w);
                }
                if(e0.fi != -1){
                    used[w] = true;
                    que.push(e0);
                    G.add_Undirected_edge(e0.fi, e0.se);
                }
            }
        }
        bool ok = true;
        REP(i, n) if(!used[i]) ok = false;
        if(ok){
            mat d(n, vec(n, -1));
            REP(i, n) G.dfs(i, d[i], -1);
            //mdebug(d);
            REP(a, n) FOR(b, a + 1, n) REP(c, n){
                int res = (d[a][c] == d[b][c]);
                //debug(res); debug(s[a][c][b]);
                if(res != s[a][b][c] - '0') ok = false;
            }
        }

        if(ok){
            Out("Yes");
            REP(i, n){
                for(auto e: G.E[i]){
                    int j = e.to;
                    if(i < j) cout << i + 1 << ' ' << j + 1 << endl;
                }
            }
            return;
        }
    }
    Out("No");
}

signed main(){

    int t; cin >> t;
    REP(_, t){
        solve();
    }

    return 0;
}