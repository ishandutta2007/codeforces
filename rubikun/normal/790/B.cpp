#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<30;
vector<int> G[MAX];
int N,K;
int dp[MAX][5];
int dis[MAX];

ll ans=0,sum=0;

void DFS(int u,vector<int> p){
    
    for(int to:G[u]){
        if(to==p.back()) continue;
        
        vector<int> pp(K);
        for(int i=0;i<K-1;i++) pp[i]=p[i+1];
        pp[K-1]=u;
        
        dis[to]=dis[u]+1;
        ans+=(dis[to]+K-1)/K;
        
        DFS(to,pp);
    }
    
    for(int i=0;i<K;i++){
        if(p[i]!=-1){
            dp[p[i]][(K-i)%K]+=1+dp[u][0];
        }
    }
}

void solve(int u,int p){
    
    for(int to:G[u]){
        if(to==p) continue;
        
        sum-=dp[to][0];
        sum+=dp[u][0]-dp[to][K-1];
        
        //cout<<dp[to][0]<<" "<<dp[u][0]<<" "<<dp[to][K-1]<<endl;
        
        ans+=sum;
        
        vector<int> S(K),T(K);
        for(int i=0;i<K;i++){
            S[i]=dp[u][i];
            T[i]=dp[to][i];
        }
        
        /*for(int i=0;i<K;i++){
            dp[u][i]-=T[(i+K-1)%K];
            if(i==1) dp[u][i]--;
        }*/
        
        for(int i=0;i<K;i++){
            dp[to][i]+=S[(i+K-1)%K]-T[(i+2*K-2)%K];
            if((i+2*K-2)%K==0) dp[to][i]--;
            if(i==1) dp[to][i]++;
        }
        
        /*cout<<to<<" ";
        for(int i=0;i<K;i++) cout<<dp[u][i]<<" ";
        for(int i=0;i<K;i++) cout<<dp[to][i]<<" ";
        cout<<endl;*/
        
        //cout<<to<<" "<<sum<<endl;
        
        int s=0;
        for(int i=0;i<K;i++) s+=dp[to][i];
        //cout<<s<<endl;
        
        solve(to,u);
        
        for(int i=0;i<K;i++){
            dp[u][i]=S[i];
            dp[to][i]=T[i];
        }
        
        sum+=dp[to][0];
        sum-=dp[u][0]-dp[to][K-1];
        
    }
    
}

int siz[MAX];

void DD(int u,int p){
    for(int to:G[u]){
        if(to==p) continue;
        
        dis[to]=dis[u]+1;
        sum+=dis[to];
        
        DD(to,u);
        
        siz[u]+=siz[to];
    }
    
    siz[u]++;
}

void so(int u,int p){
    for(int to:G[u]){
        if(to==p) continue;
        
        sum+=N-siz[to]*2;
        ans+=sum;
        
        so(to,u);
        
        sum-=N-siz[to]*2;
    }
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
    
    if(K==1){
        DD(0,-1);
        ans=sum;
        
        so(0,-1);
        
        cout<<ans/2<<endl;
        
        return 0;
    }
    
    vector<int> p(K,-1);
    
    DFS(0,p);
    sum=ans;
    
    solve(0,-1);
    
    cout<<ans/2<<endl;
    
}