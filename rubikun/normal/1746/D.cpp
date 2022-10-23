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
map<ll,ll> dp[MAX];
ll S[MAX];

ll solve(int u,ll can){
    if(dp[u].count(can)) return dp[u][can];
    if(si(G[u])==0){
        return S[u]*can;
    }
    ll mi=can/si(G[u]);
    ll sum=S[u]*can;
    
    vector<ll> diff;
    for(int to:G[u]){
        if(can%si(G[u])==0){
            ll a=solve(to,mi);
            sum+=a;
        }else{
            ll a=solve(to,mi);
            ll b=solve(to,mi+1);
            sum+=a;
            diff.push_back(b-a);
        }
    }
    
    sort(all(diff));
    reverse(all(diff));
    for(int i=0;i<can%si(G[u]);i++){
        sum+=diff[i];
    }
    
    return dp[u][can]=sum;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        for(int i=0;i<N;i++){
            G[i].clear();
            dp[i].clear();
            S[i]=0;
        }
        
        for(int i=1;i<N;i++){
            int p;cin>>p;p--;
            G[p].push_back(i);
        }
        
        for(int i=0;i<N;i++) cin>>S[i];
        
        cout<<solve(0,K)<<"\n";
    }
}