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
const int mod=1000000007,MAX=200005,INF=1<<30;

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
    
    int N;cin>>N;
    vector<ll> X(N);
    for(int i=0;i<N;i++) cin>>X[i];
    
    sort(all(X));
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        ans+=rui(2,i)*X[i]%mod;
        ans%=mod;
        
        ans-=rui(2,N-1-i)*X[i]%mod;
        if(ans<0) ans+=mod;
    }
    
    cout<<ans<<endl;
}