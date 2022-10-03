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
const int mod=1000000007,MAX=1005,INF=1<<30;

struct UF{
    int n;
    vector<int> par,size,u,d,l,r;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        u.assign(n,INF);
        d.assign(n,-1);
        l.assign(n,INF);
        r.assign(n,-1);
        
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
            chmin(u[root(a)],u[root(b)]);
            chmax(d[root(a)],d[root(b)]);
            chmin(l[root(a)],l[root(b)]);
            chmax(r[root(a)],r[root(b)]);
            size[root(a)]+=size[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

int imo[MAX][MAX],cnt[MAX][MAX];
int seen[MAX*MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    
    if(N==K){
        cout<<N*N<<endl;
        return 0;
    }
    vector<string> S(N);
    for(int i=0;i<N;i++) cin>>S[i];
    
    UF uf;
    uf.init(N*N);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(S[i][j]=='.'){
                uf.u[i*N+j]=i;
                uf.d[i*N+j]=i;
                uf.l[i*N+j]=j;
                uf.r[i*N+j]=j;
            }else{
                uf.size[i*N+j]=0;
                cnt[i+1][j+1]++;
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i+1<N){
                if(S[i][j]=='.'&&S[i+1][j]=='.') uf.unite(i*N+j,(i+1)*N+j);
            }
            if(j+1<N){
                if(S[i][j]=='.'&&S[i][j+1]=='.') uf.unite(i*N+j,i*N+j+1);
            }
        }
    }
    
    set<int> root;
    for(int i=0;i<N*N;i++){
        int a=uf.root(i);
        if(uf.size[a]) root.insert(a);
    }
    
    for(int a:root){
        int u,d,l,r;
        u=uf.u[a]-1;
        d=uf.d[a]+1;
        l=uf.l[a]-1;
        r=uf.r[a]+1;
        
        if(d-u<=K-1&&r-l<=K-1){
            imo[u+K][l+K]+=uf.size[a];
            imo[d][r]+=uf.size[a];
            imo[u+K][r]-=uf.size[a];
            imo[d][l+K]-=uf.size[a];
        }
    }
    
    for(int j=0;j<=N;j++){
        for(int i=1;i<=N;i++){
            imo[i][j]+=imo[i-1][j];
            cnt[i][j]+=cnt[i-1][j];
        }
    }
    
    for(int i=0;i<=N;i++){
        for(int j=1;j<=N;j++){
            imo[i][j]+=imo[i][j-1];
            cnt[i][j]+=cnt[i][j-1];
        }
    }
    
    int ans=0;
    
    memset(seen,-1,sizeof(seen));
    
    vector<int> A={-1,0,K-1,K};
    
    for(int h=0;h+K<=N;h++){
        for(int w=0;w+K<=N;w++){
            
            int sum=0;
            
            for(int j=w;j<w+K;j++){
                for(int x:A){
                    if(h+x<0||h+x>=N) continue;
                    int a=uf.root((h+x)*N+j);
                    if(seen[a]!=h*N+w) sum+=uf.size[a];
                    seen[a]=h*N+w;
                }
            }
            for(int i=h;i<h+K;i++){
                for(int x:A){
                    if(w+x<0||w+x>=N) continue;
                    int a=uf.root(i*N+(w+x));
                    if(seen[a]!=h*N+w) sum+=uf.size[a];
                    seen[a]=h*N+w;
                }
            }
            
            sum+=imo[h+K-1][w+K-1];
            
            sum+=cnt[h+K][w+K]+cnt[h][w]-cnt[h+K][w]-cnt[h][w+K];
            
            chmax(ans,sum);
        }
    }
    
    cout<<ans<<endl;
}