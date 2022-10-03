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

struct UF{
    int n;
    vector<int> par,size;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

int N;

vector<int> G[MAX];

const int MAX_LOG=20;
int parr[MAX_LOG][MAX],depth[MAX];

void init(int u){
    for(int i=0;i<N;i++){
        depth[i]=INF;
        for(int j=0;j<20;j++){
            parr[j][i]=-1;
        }
    }
    queue<int> Q;
    Q.push(u);
    depth[u]=0;
    while(!Q.empty()){
        int a=Q.front();
        Q.pop();
        for(int to:G[a]){
            if(chmin(depth[to],depth[a]+1)){
                parr[0][to]=a;
                Q.push(to);
            }
        }
    }
    
    for(int k=0;k+1<MAX_LOG;k++){
        for(int i=0;i<N;i++){
            if(parr[k][i]<0) parr[k+1][i]=-1;
            else parr[k+1][i]=parr[k][parr[k][i]];
        }
    }
}

int lca(int u,int v){
    if(depth[u]>depth[v]) swap(u,v);
    for(int i=0;i<20;i++){
        if(((depth[v]-depth[u])>>i)&1) v=parr[i][v];
    }
    if(u==v) return u;
    
    for(int i=19;i>=0;i--){
        if(parr[i][u]!=parr[i][v]){
            u = parr[i][u];
            v = parr[i][v];
        }
    }
    return parr[0][u];
}


int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int M;cin>>N>>M;
    vector<int> zi(N);
    UF uf;uf.init(N);
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;a--;b--;
        if(!uf.check(a,b)){
            uf.unite(a,b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
    }
    
    int Q;cin>>Q;
    vector<pair<int,int>> E(Q);
    for(int i=0;i<Q;i++){
        int a,b;cin>>a>>b;a--;b--;
        E[i]=mp(a,b);
        zi[a]++;
        zi[b]++;
    }
    
    int need=0;
    for(int i=0;i<N;i++){
        if(zi[i]&1) need++;
    }
    
    if(need){
        cout<<"NO\n";
        cout<<need/2<<"\n";
        return 0;
    }
    
    init(0);
    
    cout<<"YES\n";
    for(int i=0;i<Q;i++){
        int a=E[i].fi,b=E[i].se,c=lca(a,b);
        vector<int> A;
        while(a!=c){
            A.push_back(a);
            a=parr[0][a];
        }
        A.push_back(c);
        vector<int> B;
        while(b!=c){
            B.push_back(b);
            b=parr[0][b];
        }
        reverse(all(B));
        for(int x:B) A.push_back(x);
        cout<<si(A)<<"\n";
        for(int x:A) cout<<x+1<<" ";
        cout<<"\n";
    }
    
    
}