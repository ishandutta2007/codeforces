#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2005,INF=1<<30;
ll pa,pb,K;
ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

ll dp[MAX][MAX];

ll solve(ll i,ll j){
    if(i>=K) return i;
    if(j==K){
        ll m=(mod+1-pb*rui(pa+pb,mod-2)%mod)*rui(pb*rui(pa+pb,mod-2)%mod,mod-2)%mod;
        return (m+K+i)%mod;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=(solve(i,j+1)*pa+solve(i+j,j)*pb)%mod*rui(pa+pb,mod-2)%mod;
}//aba

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    memset(dp,-1,sizeof(dp));
    cin>>K;
    cin>>pa>>pb;
    
    cout<<solve(0,1)<<endl;
}