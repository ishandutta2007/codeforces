#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N = 105, MAX_V = 6450;
const short INF = 32000;

typedef pair<short, short> P;
struct edge{short to, cap, cost, rev;};

int n,m,k;
int num[N][N];

struct mcostflow{

    int V; //Please set V!!!!
    vector<edge> G[MAX_V];
    short h[MAX_V];
    short dist[MAX_V];
    short prevv[MAX_V], preve[MAX_V];
//    int ord[N][N], stk[N][N], cst[N][N][N];

    void add_edge(short from, short to, short cap, short cost){
        G[from].push_back((edge){to, cap, cost, (short)G[to].size()});
        G[to].push_back((edge){from, 0, (short)(-cost), (short)((short)G[from].size() - 1)});
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

            short d = f;
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

}flow;

bool in_bound(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> num[i][j];
    }
    int s = n * m, t = n * m + 1;
    flow.V = n * m + 2;
    int hf = n * m / 2;
    for(int i = 0; i < hf; i++) flow.add_edge(s, i, 1, 0);
    for(int i = hf; i < hf * 2; i++) flow.add_edge(i, t, 1, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int v = i * m + j;
            if((i + j) % 2 == 1) continue;
            v /= 2;
            for(int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if(in_bound(ni, nj)) {
                    int nv = (ni * m + nj) / 2 + hf;
                    flow.add_edge(v, nv, 1, num[i][j] != num[ni][nj]);
                }
            }
        }
    }
    cout << flow.min_cost_flow(s, t, hf) << endl;

}