#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
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
    
    string S;cin>>S;
    ll ans=0,cnt=0;
    
    for(int i=S.size()-1;i>=0;i--){
        if(S[i]=='b') cnt++;
        else{
            ans+=cnt;
            ans%=mod;
            cnt*=2;
            cnt%=mod;
        }
    }
    
    cout<<ans<<endl;
}