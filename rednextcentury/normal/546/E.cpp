#include<bits/stdc++.h>
using namespace std;
const int INF = 2000000000;

struct Edge {
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) {}
};

int nn;
int f[1000][1000];

struct Dinic {
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

    void AddEdge(int from, int to, int cap) {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t) {
        fill(dad.begin(), dad.end(), (Edge *) NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail) {
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++) {
                Edge &e = G[x][i];
                if (!dad[e.to] && e.cap - e.flow > 0) {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if (!dad[t]) return 0;

        long long totflow = 0;
        for (int i = 0; i < G[t].size(); i++) {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                if (!e) { amt = 0; break; }
                amt = min(amt, e->cap - e->flow);
            }
            if (amt == 0) continue;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t) {
        long long totflow = 0;
        while (long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }

    void fill_it(){
        for(int i=0;i<G.size();i++) for(int j=0;j<G[i].size();j++){
            if(G[i][j].cap>0 and G[i][j].from>=1 and G[i][j].from<=nn){
                f[G[i][j].from-1][G[i][j].to-nn-1]=G[i][j].flow;
            }
        }
    }
};
int a[10000],b[10000];
int main()
{
    int n,m;
    cin>>n>>m;
    nn=n;
    int s1=0,s2=0;
    for (int i=1;i<=n;i++)
        cin>>a[i],s1+=a[i];
    for (int i=1;i<=n;i++)
        cin>>b[i],s2+=b[i];
    int s=0,t=2*n+1;
    Dinic dinic(2*n+2);
    for (int i=1;i<=n;i++)
        dinic.AddEdge(s,i,a[i]);
    for (int i=n+1;i<=2*n;i++)
        dinic.AddEdge(i,t,b[i-n]);
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        dinic.AddEdge(u,v+n,INF);
        dinic.AddEdge(v,u+n,INF);
    }
    for (int i=1;i<=n;i++)
        dinic.AddEdge(i,i+n,INF);
    int ret=dinic.GetMaxFlow(s,t);
    if (s1!=s2 || ret!=s1)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        dinic.fill_it();
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++)
                cout<<f[i][j]<<' ';
            cout<<endl;
        }

    }
}