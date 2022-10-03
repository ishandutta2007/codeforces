#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=300005,INF=1<<30;

vector<int> G[MAX];
int dis[MAX],par[MAX];

void ans(vector<int> A){
    if(si(A)==0) cout<<-1<<endl;
    else{
        cout<<si(A)<<endl;
        cout<<1<<" ";
        for(int a:A) cout<<a+1<<" ";
        cout<<endl;
    }
    exit(0);
}

struct UF{
    int n;
    vector<int> par,size,edge;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        edge.assign(n,0);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        edge[root(a)]++;
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            edge[root(a)]+=edge[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};


int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    
    set<pair<int,int>> SE;
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        if(a>b) swap(a,b);
        G[a].push_back(b);
        G[b].push_back(a);
        
        SE.insert(mp(a,b));
        
        if(a==0&&b==N-1){
            ans({N-1});
        }
    }
    
    if(si(G[0])==0) ans({});
    
    for(int u=1;u<N-1;u++){
        bool f=false,g=false;
        for(int to:G[u]){
            if(to==0) f=true;
            if(to==N-1) g=true;
        }
        if(f&&g) ans({u,N-1});
    }
    
    for(int i=0;i<N;i++){
        dis[i]=INF;
        par[i]=-1;
    }
    dis[0]=0;
    
    queue<int> Q;
    Q.push(0);
    
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int to:G[u]){
            if(chmin(dis[to],dis[u]+1)){
                par[to]=u;
                Q.push(to);
            }
        }
    }
    
    assert(dis[N-1]>2);
    
    if(dis[N-1]==3){
        int a=par[N-1],b=par[a];
        assert(par[b]==0);
        ans({b,a,N-1});
    }
    
    if(dis[N-1]==4){
        int a=par[N-1],b=par[a],c=par[b];
        assert(par[c]==0);
        ans({c,b,a,N-1});
    }
    
    for(int u=1;u<N-1;u++){
        bool f=false,g=false;
        for(int to:G[u]){
            if(to==0) f=true;
            if(to==N-1) g=true;
        }
        if(f){
            for(int to:G[u]){
                if(to==0) continue;
                if(!SE.count(mp(0,to))) ans({u,to,0,N-1});
            }
        }
    }
    
    UF uf;
    uf.init(N);
    
    for(auto e:SE){
        if(e.fi) uf.unite(e.fi,e.se);
    }
    
    for(int i=1;i<N;i++){
        if(uf.root(i)!=i) continue;
        ll v=uf.size[i],e=uf.edge[i];
        if(v*(v-1)/2==e) continue;
        if(!SE.count(mp(0,i))) continue;
        
        for(int j=1;j<N;j++){
            if(!uf.check(i,j)) continue;
            if(si(G[j])<v){
                for(int u=1;u<N-1;u++){
                    if(u==i) continue;
                    if(u==j) continue;
                    if(!uf.check(i,u)) continue;
                    
                    int a=min(u,j),b=max(u,j);
                    if(!SE.count(mp(a,b))) continue;
                    
                    for(int to:G[u]){
                        if(to==0) continue;
                        if(to==j) continue;
                        
                        int a=min(to,j),b=max(to,j);
                        if(!SE.count(mp(a,b))) ans({j,u,to,j,N-1});
                    }
                }
            }
        }
    }
    
    if(dis[N-1]!=INF){
        vector<int> a;
        int now=N-1;
        while(1){
            if(now==0) break;
            a.push_back(now);
            now=par[now];
        }
        reverse(all(a));
        ans({a});
    }
    
    ans({});
}