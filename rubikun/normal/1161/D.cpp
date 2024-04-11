#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=3005,INF=1<<30;
vector<pair<int,int>> G[MAX];
int color[MAX];
bool ok=true;
 
void DFS(int u,int p){
    for(int i=0;i<G[u].size();i++){
        int a=G[u][i].first,b=G[u][i].second;
        if(a==p) continue;
        if(b==0){
            if(color[a]==0){
                color[a]=color[u];
                DFS(a,u);
            }else if(color[a]!=color[u]) ok=false;
        }else{
            if(color[a]==0){
                color[a]=3-color[u];
                DFS(a,u);
            }else if(color[a]==color[u]) ok=false;
        }
    }
}
 
ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}
 
int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    string S;cin>>S;
    int N=int(S.size());
    ll ans=0;
    
    for(int k=1;k<N;k++){
        for(int i=0;i<2*N-k+2;i++) G[i].clear();
        memset(color,0,4*(2*N-k+2));
        ok=true;
        
        for(int i=0;i<N;i++){
            if(i!=N-1-i) G[i].push_back({N-1-i,0});
        }
        for(int i=0;i<N-k;i++){
            if(i!=N-k-1-i) G[i+N].push_back({N-k-1-i+N,0});
        }
        G[2*N-k].push_back({2*N-k+1,1});
        G[2*N-k+1].push_back({2*N-k,1});
        for(int i=0;i<N;i++){
            if(i<k&&S[i]!='?'){
                G[i].push_back({2*N-k+(S[i]-'0'),0});
                G[2*N-k+(S[i]-'0')].push_back({i,0});
            }else if(i>=k&&S[i]!='?'){
                G[i].push_back({N+i-k,S[i]-'0'});
                G[N+i-k].push_back({i,S[i]-'0'});
            }
        }
        G[N].push_back({2*N-k+1,0});
        G[2*N-k+1].push_back({N,0});
        
        ll cnt=0;
        
        for(int i=0;i<2*N-k+2;i++){
            if(color[i]==0){
                color[i]=1;
                DFS(i,-1);
                cnt++;
            }
            //if(!ok) cout<<k<<" "<<i<<endl;
        }
        
        if(ok) ans+=rui(2,cnt-1);
        
        ans%=mod;
        //cout<<ans<<endl;
        
    }
    
    cout<<ans<<endl;
}