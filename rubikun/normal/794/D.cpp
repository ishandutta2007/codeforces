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

vector<int> G2[MAX];

int ans[MAX];

void DFS(int u){
    for(int to:G2[u]){
        if(ans[to]) continue;
        ans[to]=ans[u]+1;
        DFS(to);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    
    vector<pair<vector<int>,int>> G(N);
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].fi.push_back(b);
        G[b].fi.push_back(a);
    }
    for(int i=0;i<N;i++){
        G[i].se=i;
        G[i].fi.push_back(i);
        sort(all(G[i].fi));
    }
    sort(all(G));
    
    UF uf;
    uf.init(N);
    
    for(int i=0;i+1<N;i++){
        if(G[i].fi==G[i+1].fi) uf.unite(G[i].se,G[i+1].se);
    }
    
    for(int i=0;i<N;i++){
        for(int to:G[i].fi){
            if(uf.root(G[i].se)!=uf.root(to)) G2[uf.root(G[i].se)].push_back(uf.root(to));
        }
    }
    
    set<int> SE;
    for(int i=0;i<N;i++) SE.insert(uf.root(i));
    
    vector<int> st;
    bool ok=true;
    
    for(int i=0;i<N;i++){
        if(si(G2[i])){
            sort(all(G2[i]));
            G2[i].erase(unique(all(G2[i])),G2[i].end());
        }
        if(si(G2[i])==1) st.push_back(i);
        else if(si(G2[i])>=3) ok=false;
    }
    
    if(si(SE)>=2&&si(st)==0) ok=false;
    
    if(!ok) cout<<"NO"<<endl;
    else if(si(st)==0){
        cout<<"YES"<<endl;
        for(int i=0;i<N;i++) cout<<1<<" ";
        cout<<endl;
    }else {
        ans[st[0]]=1;
        DFS(st[0]);
        
        cout<<"YES"<<endl;
        
        for(int i=0;i<N;i++){
            cout<<ans[uf.root(i)]<<" ";
        }
        cout<<endl;
    }
}