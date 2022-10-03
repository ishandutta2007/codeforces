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
const int mod=1000000007,MAX=100005,INF=1<<30;

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

vector<int> G1[MAX];

const int MAX_LOG=20;
int parr1[MAX_LOG][MAX],depth1[MAX];

int N;

void init1(int u){
    for(int i=0;i<N;i++){
        depth1[i]=INF;
        for(int j=0;j<20;j++){
            parr1[j][i]=-1;
        }
    }
    queue<int> Q;
    Q.push(u);
    depth1[u]=0;
    while(!Q.empty()){
        int a=Q.front();
        Q.pop();
        for(int to:G1[a]){
            if(chmin(depth1[to],depth1[a]+1)){
                parr1[0][to]=a;
                Q.push(to);
            }
        }
    }
    
    for(int k=0;k+1<MAX_LOG;k++){
        for(int i=0;i<N;i++){
            if(parr1[k][i]<0) parr1[k+1][i]=-1;
            else parr1[k+1][i]=parr1[k][parr1[k][i]];
        }
    }
}

int lca1(int u,int v){
    if(depth1[u]>depth1[v]) swap(u,v);
    for(int i=0;i<20;i++){
        if(((depth1[v]-depth1[u])>>i)&1) v=parr1[i][v];
    }
    if(u==v) return u;
    
    for(int i=19;i>=0;i--){
        if(parr1[i][u]!=parr1[i][v]){
            u = parr1[i][u];
            v = parr1[i][v];
        }
    }
    return parr1[0][u];
}

vector<pair<int,int>> G2[MAX];

//const int MAX_LOG=20;
int par1[MAX_LOG][MAX];
int parr2[MAX_LOG][MAX],depth2[MAX];

//int N;

void init2(int u){
    for(int i=0;i<N;i++){
        depth2[i]=INF;
        for(int j=0;j<20;j++){
            par1[j][i]=-1;
            parr2[j][i]=-1;
        }
    }
    queue<int> Q;
    Q.push(u);
    depth2[u]=0;
    while(!Q.empty()){
        int a=Q.front();
        Q.pop();
        for(auto to:G2[a]){
            if(chmin(depth2[to.fi],depth2[a]+1)){
                if(to.se==1) par1[0][to.fi]=a;
                if(to.se==2) parr2[0][to.fi]=a;
                Q.push(to.fi);
            }
        }
    }
    for(int k=0;k+1<MAX_LOG;k++){
        for(int i=0;i<N;i++){
            if(par1[k][i]<0) par1[k+1][i]=-1;
            else par1[k+1][i]=par1[k][par1[k][i]];
        }
    }
    for(int k=0;k+1<MAX_LOG;k++){
        for(int i=0;i<N;i++){
            if(parr2[k][i]<0) parr2[k+1][i]=-1;
            else parr2[k+1][i]=parr2[k][parr2[k][i]];
        }
    }
}

bool lca2(int u,int v){
    //if(depth2[u]>depth2[v]) swap(u,v);
    for(int i=0;i<20;i++){
        if(depth2[u]>depth2[v]){
            if(((depth2[u]-depth2[v])>>i)&1) u=par1[i][u];
        }
        if(depth2[u]<depth2[v]){
            if(((depth2[v]-depth2[u])>>i)&1) v=parr2[i][v];
        }
        if(u==-1||v==-1) return false;
    }
    if(u==v&&u!=-1) return true;
    
    for(int i=19;i>=0;i--){
        if(par1[i][u]!=parr2[i][v]&&par1[i][u]!=-1&&parr2[i][v]!=-1){
            u = par1[i][u];
            v = parr2[i][v];
        }
        if(u==-1||v==-1) return false;
    }
    if(u==v&&u!=-1) return true;
    if(par1[0][u]==parr2[0][v]&&par1[0][u]!=-1) return true;
    return false;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    UF uf;uf.init(N+1);
    vector<pair<int,int>> E;
    for(int i=1;i<=N;i++){
        int p,t;cin>>p>>t;
        if(p==-1){
            E.push_back(mp(0,i));
            G1[0].push_back(i);
            G2[0].push_back(mp(i,0));
        }else if(t==0){
            uf.unite(p,i);
            G1[p].push_back(i);
            G2[p].push_back(mp(i,1));
        }else{
            G1[0].push_back(i);
            G2[p].push_back(mp(i,2));
        }
    }
    
    N++;
    init1(0);
    init2(0);
    
    int Q;cin>>Q;
    while(Q--){
        int t,a,b;cin>>t>>a>>b;
        if(a==b){
            cout<<"NO\n";
            continue;
        }
        if(t==1){
            if(uf.check(a,b)&&lca1(a,b)==a) cout<<"YES\n";
            else cout<<"NO\n";
        }else{
            //int c=lca2(a,b);
            if(!uf.check(a,b)&&lca2(a,b)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}