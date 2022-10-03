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
const int mod=1000000007,MAX=105,INF=1<<30;
int N,K;
vector<int> G[MAX];
ll dp[MAX][MAX][23],dp2[MAX][MAX][23];
int dep[MAX];

void mae(int u,int p){
    dep[u]=1;
    for(int to:G[u]){
        if(to==p) continue;
        mae(to,u);
        chmax(dep[u],dep[to]+1);
    }
}

void DFS(int u,int p){
    
    dp[u][2*K+1][1]=1;
    
    ll a=1;
    
    for(int to:G[u]){
        if(to==p) continue;
        
        DFS(to,u);
        
        ll sum=0;
        for(int i=1;i<=2*K+1;i++){
            for(int j=0;j<=K;j++){
                sum+=dp[to][i][j];
                sum%=mod;
            }
        }
        a*=sum;
        a%=mod;
        
        for(int iu=1;iu<=2*K+1;iu++){
            for(int ju=0;ju<=K;ju++){
                for(int ich=1;ich<=2*K+1;ich++){
                    for(int jch=0;jch<=K;jch++){
                        ll s=dp[u][iu][ju]*dp[to][ich][jch]%mod;
                        
                        if(K-iu+1>=jch||!jch){
                            if(K-ich+1>=ju||!ju){
                                dp2[u][min(iu,ich+1)][0]+=s;
                                dp2[u][min(iu,ich+1)][0]%=mod;
                            }else{
                                dp2[u][min(iu,ich+1)][ju]+=s;
                                dp2[u][min(iu,ich+1)][ju]%=mod;
                            }
                        }else{
                            int too=0;
                            if(jch) too=jch+1;
                            if(K-ich+1>=ju||!ju){
                                dp2[u][min(iu,ich+1)][too]+=s;
                                dp2[u][min(iu,ich+1)][too]%=mod;
                            }else{
                                dp2[u][min(iu,ich+1)][max(ju,too)]+=s;
                                dp2[u][min(iu,ich+1)][max(ju,too)]%=mod;
                            }
                        }
                    }
                }
            }
        }
        
        for(int ii=1;ii<=2*K+1;ii++){
            for(int jj=0;jj<=K;jj++){
                dp[u][ii][jj]=dp2[u][ii][jj];
                dp2[u][ii][jj]=0;
            }
        }
    }
    
    dp[u][1][0]+=a;
    dp[u][1][0]%=mod;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>K;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    mae(0,-1);
    DFS(0,-1);
    
    ll ans=0;
    
    for(int i=1;i<=2*K+1;i++){
        ans+=dp[0][i][0];
        ans%=mod;
    }
    
    cout<<ans<<endl;
}