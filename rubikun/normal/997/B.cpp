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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N;cin>>N;
    
    ll ans=0;
    
    if(N>=5){
        if(N==5) ans=1;
        else if(N==6) ans=3;
        else if(ans==7) ans=6;
        else ans=6+(N-7)*4;
    }
    
    for(ll k=4;k>=0;k--){
        if(N>=k){
            if(N-k>=8) ans+=N-k-8+1;
            ll mi=max(N-k-7+1,0LL);
            ll ma=N-k+1;
            ans+=(mi+ma)*(ma-mi+1)/2;
        }
    }
    
    cout<<ans<<endl;
    
}