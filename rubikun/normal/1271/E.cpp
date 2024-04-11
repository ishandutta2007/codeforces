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
    
    ll N,K;cin>>N>>K;
    ll ans=1;
    
    ll left=1,right;
    if(N%2==1) right=N+2;
    else right=N+1;
    
    while(right-left>2){
        ll mid=(left+right)/2/2*2+1;
        
        ll le=mid,ri=mid;
        ll cnt=1;
        
        while(1){
            le*=2;
            ri=ri*2+1;
            
            if(le>N) break;
            
            if(ri<=N){
                cnt+=ri-le+1;
            }else{
                cnt+=N-le+1;
                break;
            }
        }
        
        if(cnt>=K) left=mid;
        else right=mid;
    }
    
    ans=max(ans,left);
    
    left=0;
    if(N%2==1) right=N+1;
    else right=N+2;
    
    while(right-left>2){
        ll mid=(left+right)/2/2*2;
        
        ll le=mid,ri=mid+1;
        ll cnt;
        if(ri<=N) cnt=2;
        else cnt=1;
        
        while(1){
            le*=2;
            ri=ri*2+1;
            
            if(le>N) break;
            
            if(ri<=N){
                cnt+=ri-le+1;
            }else{
                cnt+=N-le+1;
                break;
            }
        }
        
        if(cnt>=K) left=mid;
        else right=mid;
    }
    
    ans=max(ans,left);
    
    cout<<ans<<endl;
}