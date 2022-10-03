#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,Q;cin>>N>>Q;
    while(Q--){
        ll x,y;cin>>x>>y;
        swap(x,y);
        if(N%2==0){
            ll ans=0;
            if((x+y)%2==0){
                ans+=(y-1)*(N/2);
                ans+=(x+1)/2;
            }else{
                ans+=N*N/2;
                ans+=(y-1)*(N/2);
                ans+=(x+1)/2;
            }
            cout<<ans<<endl;
        }else{
            ll ans=0;
            if((x+y)%2==0){
                if(y%2==1){
                    ans+=y/2*N;
                    ans+=(x+1)/2;
                }else{
                    ans+=(y-1)/2*N;
                    ans+=(N+1)/2;
                    ans+=(x+1)/2;
                }
            }else{
                ans+=(N*N+1)/2;
                if(y%2==1){
                    ans+=y/2*N;
                    ans+=(x+1)/2;
                }else{
                    ans+=(y-1)/2*N;
                    ans+=N/2;
                    ans+=(x+1)/2;
                }
            }
            cout<<ans<<endl;
        }
    }
}