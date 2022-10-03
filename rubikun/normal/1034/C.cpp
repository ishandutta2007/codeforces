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
const int mod=1000000007,MAX=1000005,INF=1<<30;
ll ma=0;
ll A[MAX],dp[MAX];
int cnt[MAX],dp2[MAX];
vector<int> G[MAX];
int N;

void DFS(int u,int p){
    for(int to:G[u]){
        if(to==p) continue;
        
        DFS(to,u);
        
        dp[u]+=dp[to];
    }
}

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

vector<ll> ok;

ll dp3[MAX];

bool check[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
        chmax(ma,A[i]);
        dp[i]=A[i];
    }
    for(int i=1;i<N;i++){
        int a;cin>>a;
        a--;
        G[i].push_back(a);
        G[a].push_back(i);
    }
    DFS(0,-1);
    
    for(int i=0;i<N;i++){
        ll k=dp[0]/gcd(dp[0],dp[i]);
        if(k<=N) cnt[k]++;
    }
    
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j+=i){
            dp2[j]+=cnt[i];
        }
    }
    
    for(int i=1;i<=N;i++){
        if(dp2[i]>=i) check[i]=1;
    }
    
    dp3[1]=1;
    
    for(int i=1;i<=N;i++){
        if(!check[i]) continue;
        
        for(int j=i*2;j<=N;j+=i){
            if(!check[j]) continue;
            
            dp3[j]+=dp3[i];
            dp3[j]%=mod;
        }
    }
    
    ll ans=0;
    
    for(int i=1;i<=N;i++){
        ans+=dp3[i];
        ans%=mod;
    }
    
    cout<<ans<<endl;
}