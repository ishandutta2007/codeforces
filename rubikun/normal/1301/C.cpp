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
    
    int Q;cin>>Q;
    while(Q--){
        ll N,M;cin>>N>>M;
        if(M+M+1>=N){
            cout<<N*(N+1)/2-(N-M)<<endl;
        }else{
            ll a=(N-M)/(M+1);
            ll p=(N-M)-a*(M+1);
            ll ans=N*(N+1)/2;
            ans-=p*(a+1)*(a+2)/2;
            ans-=(M+1-p)*a*(a+1)/2;
            
            cout<<ans<<endl;
        }
    }
    
}