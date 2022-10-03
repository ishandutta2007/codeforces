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
const int mod=1000000007,MAX=200005,INF=1<<30;

struct UF{
    int n;
    vector<int> par,size,color;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        color.assign(n,-1);
        
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
            int c=color[root(a)],d=color[root(b)];
            size[root(a)]+=size[root(b)];
            if(c==-1) color[root(a)]=d;
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

struct dat{
    ll cost;
    int i;
    int j;
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int M,N;cin>>M>>N;
    vector<ll> A(M),B(N);
    for(int i=0;i<M;i++) cin>>A[i];
    for(int j=0;j<N;j++) cin>>B[j];
    
    vector<vector<int>> Y(M);
    
    vector<dat> S;
    
    for(int i=0;i<M;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int x;cin>>x;
            x--;
            S.push_back({A[i]+B[x],i,x});
        }
    }
    
    sort(all(S),[](auto a,auto b){
        return a.cost>b.cost;
    });
    
    ll ans=0;
    
    UF uf;
    uf.init(N);
    
    for(auto x:S){
        ll cost=x.cost;
        int i=x.i,j=x.j;
        
        //cout<<ans<<" "<<i+1<<" "<<j+1<<endl;
        
        if(si(Y[i])==0){
            Y[i].push_back(j);
            continue;
        }
        
        int d=uf.color[uf.root(j)],c=uf.color[uf.root(Y[i][0])];
        
        if(uf.check(Y[i][0],j)){
            if(c!=i) ans+=cost;
        }else{
            if((c!=-1&&c!=i)||(d!=-1&&d!=i)){
                uf.unite(Y[i][0],j);
                uf.color[uf.root(j)]=INF;
            }else{
                uf.unite(Y[i][0],j);
                uf.color[uf.root(j)]=i;
            }
        }
        
        /*if(uf.color[uf.root(Y[i][0])]==-1||uf.color[uf.root(Y[i][0])]==i){
            uf.unite(Y[i][0],j);
            uf.color[uf.root(j)]=i;
        }else if(uf.size[uf.root(j)]==1){
            uf.unite(Y[i][0],j);
        }else if(!uf.check(Y[i][0],j)){
            uf.unite(Y[i][0],j);
            uf.color[uf.root(j)]=INF;
        }else{
            ans+=cost;
        }*/
    }
    
    cout<<ans<<endl;
}