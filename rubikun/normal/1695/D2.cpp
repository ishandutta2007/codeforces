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
const int mod=998244353,MAX=200005,INF=1<<30;

vector<int> G[MAX];
int dp[MAX][2];

int ans=INF;

void make(int u,int p){
    vector<int> A;
    int sum=0;
    for(int to:G[u]){
        if(to==p) continue;
        make(to,u);
        A.push_back(dp[to][1]-dp[to][0]);
        sum+=dp[to][1];
    }
    sort(all(A));
    if(si(A)==0){
        dp[u][0]=0;
        dp[u][1]=1;
    }else if(si(A)==1){
        dp[u][0]=sum-A.back();
        dp[u][1]=sum;
    }else{
        dp[u][0]=sum-A.back();
        dp[u][1]=sum-A.back();
    }
}

void solve(int u,int p){
    vector<int> A;
    int sum=0;
    for(int to:G[u]){
        A.push_back(dp[to][1]-dp[to][0]);
        sum+=dp[to][1];
    }
    sort(all(A));
    if(si(A)==0){
        dp[u][0]=0;
        dp[u][1]=1;
    }else if(si(A)==1){
        dp[u][0]=sum-A.back();
        dp[u][1]=sum;
    }else{
        dp[u][0]=sum-A.back();
        dp[u][1]=sum-A.back();
    }
    
    chmin(ans,dp[u][0]+1);
    chmin(ans,dp[u][1]+1);
    
    vector<int> L,R;
    for(int to:G[u]){
        //sum+=dp[to][1];
        L.push_back(dp[to][1]-dp[to][0]);
    }
    R=L;
    for(int i=1;i<si(L);i++) chmax(L[i],L[i-1]);
    for(int i=si(R)-2;i>=0;i--) chmax(R[i],R[i+1]);
    
    for(int i=0;i<si(G[u]);i++){
        int to=G[u][i];
        if(to==p) continue;
        
        int a=dp[u][0],b=dp[u][1];
        int sumsum=sum-dp[to][1];
        
        if(si(L)-1==0){
            dp[u][0]=0;
            dp[u][1]=1;
        }else if(si(L)-1==1){
            int hiku=0;
            if(i) chmax(hiku,L[i-1]);
            if(i+1<si(R)) chmax(hiku,R[i+1]);
            dp[u][0]=sumsum-hiku;
            dp[u][1]=sumsum;
        }else{
            int hiku=0;
            if(i) chmax(hiku,L[i-1]);
            if(i+1<si(R)) chmax(hiku,R[i+1]);
            dp[u][0]=sumsum-hiku;
            dp[u][1]=sumsum-hiku;
        }
        
        solve(to,u);
        
        dp[u][0]=a;
        dp[u][1]=b;
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        for(int i=0;i<N;i++){
            G[i].clear();
            dp[i][0]=dp[i][1]=INF;
        }
        ans=INF;
        for(int i=0;i<N-1;i++){
            int a,b;cin>>a>>b;a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        make(0,-1);
        solve(0,-1);
        if(N==1) ans=0;
        cout<<ans<<endl;
    }
}