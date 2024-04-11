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
const int mod=1000000007,MAX=300005,INF=1<<30;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

ll dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N;cin>>N;
    ll ans=0;
    
    for(ll c=1;c<=N-2;c++){
        ll rem=N-c;
        vector<ll> use;
        for(ll i=1;i*i<=rem;i++){
            if(rem%i==0){
                use.push_back(i);
            }
        }
        for(int i=si(use)-1;i>=0;i--){
            if(use[i]*use[i]!=rem) use.push_back(rem/use[i]);
        }
        for(ll x:use){
            dp[x]=(rem/x-1);
        }
        for(int i=si(use)-1;i>=0;i--){
            for(int j=i+1;j<si(use);j++){
                if(use[j]%use[i]==0) dp[use[i]]-=dp[use[j]];
            }
            ll x=use[i];
            ans+=x*c/gcd(x,c)%mod*dp[x];
            ans%=mod;
        }
        //cout<<ans<<endl;
    }
    
    cout<<ans<<endl;
}