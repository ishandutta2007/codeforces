#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=10005;
const ll INF=1LL<<60;

struct edge{int to;ll cap;int rev;};

vector<edge> G[MAX];
int level[MAX];
int iter[MAX];

void add_edge(int from,int to,ll cap){
    G[from].push_back((edge){to,cap,int(G[to].size())});
    G[to].push_back((edge){from,0LL,int(G[from].size())-1});
}

void BFS(int s){
    memset(level,-1,sizeof(level));
    memset(iter,0,sizeof(iter));
    queue<int> que;
    level[s] =0;
    que.push(s);
    while(!que.empty()){
        int v=que.front();que.pop();
        for(int i=0;i<G[v].size();i++){
            edge &e =G[v][i];
            if(e.cap>0&&level[e.to]<0){
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}

ll DFS(int v,int t,ll f){
    if(v==t) return f;
    for(int &i=iter[v];i<G[v].size();i++){
        edge &e =G[v][i];
        if(e.cap>0&&level[v]<level[e.to]){
            ll d= DFS(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow(int s,int t){
    ll flow=0;
    for(;;){
        BFS(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        ll f;
        while((f=DFS(s,t,INF))>0){
            flow+=f;
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<int> p(N),c(N);
    for(int i=0;i<N;i++) cin>>p[i];
    for(int i=0;i<N;i++){
        cin>>c[i];
        c[i]--;
    }
    
    int Q;cin>>Q;
    vector<int> ans(Q),A(Q),ok(N,1);
    for(int i=0;i<Q;i++){
        cin>>A[i];
        A[i]--;
        ok[A[i]]=0;
    }
    
    for(int i=0;i<5000;i++){
        add_edge(5000+i,10001,1);
    }
    
    for(int i=0;i<N;i++){
        if(ok[i]) add_edge(p[i],5000+c[i],1);
    }
    add_edge(10000,0,1);
    while(max_flow(10000,10001)){
        ans[Q-1]++;
        add_edge(10000,ans[Q-1],1);
    }
    for(int i=Q-2;i>=0;i--){
        add_edge(p[A[i+1]],5000+c[A[i+1]],1);
        ans[i]=ans[i+1];
        while(max_flow(10000,10001)){
            ans[i]++;
            add_edge(10000,ans[i],1);
        }
    }
    
    for(int i=0;i<Q;i++){
        cout<<ans[i]<<"\n";
    }
    
}