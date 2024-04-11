#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<ll> S(N);
    for(int i=0;i<N;i++){
        cin>>S[i];
    }
    
    ll a=S[0];
    int cnt=0;
    while(a!=0){
        a/=10;
        cnt++;
    }
    
    vector<ll> rui(cnt);
    ll k=1;
    
    for(int i=0;i<cnt;i++){
        rui[i]=k;
        k*=100;
        k=k%mod;
    }
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        ll sum=0;
        for(int j=0;j<cnt;j++){
            sum+=rui[j]*(S[i]%10)%mod*11;
            sum=sum%mod;
            S[i]/=10;
        }
        ans+=sum*N;
        ans=ans%mod;
    }
    
    cout<<ans<<endl;
}