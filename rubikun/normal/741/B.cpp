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
const int mod=1000000007,MAX=2005,INF=1<<30;

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

int dp[MAX][MAX];

vector<pair<int,int>> U[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,W;cin>>N>>M>>W;
    UF uf;
    uf.init(N);
    
    vector<int> a(N),b(N);
    for(int i=0;i<N;i++) cin>>a[i];
    for(int i=0;i<N;i++) cin>>b[i];
    
    for(int i=0;i<M;i++){
        int aa,bb;cin>>aa>>bb;
        aa--;bb--;
        uf.unite(aa,bb);
    }
    
    for(int i=0;i<N;i++){
        U[uf.root(i)].push_back(mp(a[i],b[i]));
    }
    vector<int> T;
    
    for(int i=0;i<N;i++){
        if(si(U[i])==0) continue;
        T.push_back(i);
        int asum=0,bsum=0;
        for(int j=0;j<si(U[i]);j++){
            asum+=U[i][j].fi;
            bsum+=U[i][j].se;
        }
        if(asum<=W) U[i].push_back(mp(asum,bsum));
    }
    
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            dp[i][j]=-INF;
        }
    }
    
    dp[0][0]=0;
    
    for(int i=0;i<si(T);i++){
        for(int j=0;j<=W;j++){
            chmax(dp[i+1][j],dp[i][j]);
            for(auto x:U[T[i]]){
                chmax(dp[i+1][j+x.fi],dp[i][j]+x.se);
            }
        }
    }
    
    int ans=-INF;
    
    for(int j=0;j<=W;j++) chmax(ans,dp[si(T)][j]);
    
    cout<<ans<<endl;
    
}