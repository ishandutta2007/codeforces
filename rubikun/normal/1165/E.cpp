#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1003,INF=1<<30;

int main(){
    
    ll N;cin>>N;
    vector<ll> A(N),B(N);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<N;i++) cin>>B[i];
    
    for(ll i=0;i<N;i++){
        A[i]*=(i+1)*(N-i);
    }
    
    sort(all(A));
    reverse(all(A));
    sort(all(B));
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        ans+=A[i]%mod*B[i]%mod;
        ans%=mod;
    }
    
    cout<<ans<<endl;
    
}