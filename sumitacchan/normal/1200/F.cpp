#include <bits/stdc++.h>
using namespace std;
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


const int R = 2520;

struct edge{int to, cost, id;};

class Graph
{
public:
    int N;
    vector<vector<edge>> G;
    vec ans;

    Graph(int N): N(N){
        G = vector<vector<edge>>(N, vector<edge>(0));
    }

    void add_Directed_edge(int from, int to, int cost = 1, int id = 0){
        G[from].push_back(edge({to, cost, id}));
    }

    void add_Undirected_edge(int v1, int v2, int cost = 1, int id = 0){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }

    //SCC decomposition
    void dfs(int v, vector<bool> &used, vec &vs){
        used[v] = true;
        REP(i, G[v].size()){
            if(!used[G[v][i].to]) dfs(G[v][i].to, used, vs);
        }
        vs.push_back(v);
    }
    void rdfs(int v, int k, vector<bool> &used, vec &cmp){
        used[v] = true;
        cmp[v] = k;
        REP(i, G[v].size()){
            if(!used[G[v][i].to]) rdfs(G[v][i].to, k, used, cmp);
        }
    }
    vec scc(int &k){
        vector<bool> used(N, false);
        vec vs(0), cmp(N);
        REP(i, N){
            if(!used[i]) dfs(i, used, vs);
        }
        //reverse graph
        Graph rG(N);
        REP(v, N) REP(i, G[v].size()) rG.add_Directed_edge(G[v][i].to, v, G[v][i].cost);

        fill(used.begin(), used.end(), false);
        k = 0;
        IREP(i, vs.size()){
            if(!used[vs[i]]) rG.rdfs(vs[i], k++, used, cmp);
        }
        ans = vec(k, -1);
        return cmp;
    }


    void roop(int v, int v0, int c, set<int> &s){
        if(v0 == v){
            c++;
            if(c >= 2) return;
        }
        s.insert(v / R);
        roop(G[v][0].to, v0, c, s);
    }

    int calcans(int v, vec &cmp, vec &cnt){
        int u = cmp[v];
        if(ans[u] != -1) return ans[u];
        if(G[v][0].to == v) return ans[u] = 1;
        if(cnt[u] >= 2){
            set<int> s;
            roop(v, v, 0, s);
            return ans[u] = SZ(s);
        }
        return ans[u] = calcans(G[v][0].to, cmp, cnt);
    }


    

};


signed main(){

    int n; cin >> n;
    vec k(n); cin >> k;
    vec m(n);
    Graph G(n * R);
    REP(i, n){
        cin >> m[i];
        vec t(m[i]); cin >> t;
        REP(j, R){
            int to = t[j % m[i]] - 1;
            int r = ((j + k[to]) % R + R) % R;
            G.add_Directed_edge(i * R + j, to * R + r);
        } 
    }

    int N;
    vec cmp = G.scc(N);
    vec cnt(N, 0);
    REP(i, n * R) cnt[cmp[i]]++;
    REP(i, n * R) G.calcans(i, cmp, cnt);

    int q; cin >> q;
    vec ans(q);
    REP(i, q){
        int x, y; cin >> x >> y;
        x--;
        y = ((y + k[x]) % R + R) % R;
        ans[i] = G.ans[cmp[x * R + y]];
    }
    REP(i, q) cout << ans[i] << '\n';

    return 0;
}