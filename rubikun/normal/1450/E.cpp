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
const int mod=998244353,MAX=205,INF=1<<29;

//Union Find


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

int dis[MAX][MAX];

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    UF uf;uf.init(2*N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dis[i][j]=INF;
        }
        dis[i][i]=0;
    }
    
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;a--;b--;
        uf.unite(a,N+b);
        uf.unite(b,N+a);
        if(c==0){
            chmin(dis[a][b],1);
            chmin(dis[b][a],1);
        }else{
            chmin(dis[a][b],1);
            chmin(dis[b][a],-1);
        }
    }
    
    for(int k=0;k<N;k++){
        if(uf.check(k,N+k)){
            cout<<"NO\n";
            return 0;
        }
    }
    
    for(int k=0;k<N;k++) for(int i=0;i<N;i++) for(int j=0;j<N;j++) chmin(dis[i][j],dis[i][k]+dis[k][j]);
    
    for(int k=0;k<N;k++){
        if(dis[k][k]<0){
            cout<<"NO\n";
            return 0;
        }
    }
    
    pair<int,pair<int,int>> ma=mp(-1,mp(-1,-1));
    
    for(int s=0;s<N;s++){
        for(int t=0;t<N;t++){
            chmax(ma,mp(dis[s][t],mp(s,t)));
        }
    }
    
    cout<<"YES\n";
    cout<<ma.fi<<"\n";
    for(int i=0;i<N;i++){
        cout<<dis[ma.se.fi][i]<<" ";
    }
    cout<<"\n";
}