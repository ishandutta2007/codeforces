#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<20;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N),B(N),C(N);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<N;i++) cin>>B[i];
    for(int i=0;i<N;i++) C[i]=A[i]-B[i];
    
    sort(all(C));
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        ans+=N-int(upper_bound(all(C),-C[i])-C.begin());
        if(C[i]>0) ans--;
        
        //cout<<ans<<endl;
    }
    
    ans/=2;
    cout<<ans<<endl;
    
}