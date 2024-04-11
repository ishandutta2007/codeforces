#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N;cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        ans+=A[i]*(N+1-A[i]);
    }
    
    for(int i=0;i+1<N;i++){
        ll a=min(A[i],A[i+1]),b=max(A[i],A[i+1]);
        
        ans-=a*(N+1-b);
    }
    
    cout<<ans<<endl;
}