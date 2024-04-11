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
const int mod=998244353,MAX=300005,INF=1<<30;

ll dp[MAX];

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
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N;cin>>N;
    vector<int> A(N);
    ll S=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        S+=A[i];
    }
    
    dp[0]=N-1;
    for(ll i=1;i<S;i++){
        ll ri=i*dp[i-1]+S;
        ri%=mod;
        
        ll le=(S-i-(S-i)*(N-2)%mod*rui(N-1,mod-2)%mod+mod)%mod;
        ri*=rui(le,mod-2);
        ri%=mod;
        
        dp[i]=ri;
    }
    
    for(ll i=S-1;i>=0;i--){
        dp[i]+=dp[i+1];
        dp[i]%=mod;
    }
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        ans+=dp[A[i]];
        ans%=mod;
    }
    
    ans+=mod-dp[0]*(N-1)%mod;
    ans%=mod;
    
    ans*=rui(N,mod-2);
    ans%=mod;
    
    cout<<ans<<endl;
    
}