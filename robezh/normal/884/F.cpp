#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 26 * 100 + 5, MAX_V = 26 * 100 + 5, INF = (int)1e9;

typedef pair<int, int> P;
struct edge{int to, cap, cost, rev;};

// Finding Min Cost Max Flow in min(O(F * E * log(V), O(F * V * V));
struct MincostFlow {
    int V; //Please set V!!!!
    vector<edge> G[MAX_V];
    int h[MAX_V];
    int dist[MAX_V];
    int prevv[MAX_V], preve[MAX_V];

    void add_edge(int from, int to, int cap, int cost){
        G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
        G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
    }

    int min_cost_flow(int s, int t, int f){
        int res = 0;
        fill(h, h + V, 0);
        while(f > 0){
            priority_queue<P, vector<P>, greater<P> > que;
            fill(dist, dist + V, INF);
            dist[s] = 0;
            que.push(P(0, s));
            while(!que.empty()){
                P p = que.top(); que.pop();
                int v = p.second;
                if(dist[v] < p.first) continue;
                for(int i = 0; i < G[v].size(); i++){
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        que.push(P(dist[e.to], e.to));
                    }
                }
            }
            if(dist[t] == INF) return -1;
            for(int v = 0; v < V; v++) h[v] += dist[v];

            int d = f;
            for(int v = t; v != s; v = prevv[v]){
                d = min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * h[t];
            for(int v = t; v != s; v = prevv[v]){
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }

} mf;

string str;
int n, b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);



    cin >> n;
    cin >> str;

    int s = n / 2 * (26 + 1) + n, t = s + 1;
    mf.V = t + 1;

    int sum = 0;
    rep(i, 0, n) cin >> b[i], sum += b[i];
    rep(i, 0, n) mf.add_edge(s, i, 1, 0);
    rep(i, 0, n / 2) {
        rep(j, 0, n / 2) {
            mf.add_edge(i, n + 27 * j + (str[i] - 'a'), 1, (i == j ? 0 : b[i]));
            int ni = n - 1 - i;
            mf.add_edge(ni, n + 27 * j + (str[ni] - 'a'), 1, (i == j ? 0 : b[ni]));
        }
        rep(j, 0, 26) {
            mf.add_edge(n + 27 * i + j, n + 27 * i + 26, 1, 0);
        }
        mf.add_edge(n + 27 * i + 26, t, 2, 0);
    }
    int flow = mf.min_cost_flow(s, t, n);
//    cout << flow << endl;
    cout << sum - flow << endl;



}