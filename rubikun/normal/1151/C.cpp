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
    
    ll L,R;cin>>L>>R;
    L--;
    
    ll now=1,sum=0,leftcnt=0,rightcnt=0,turn=0;
    
    while(1){
        if(sum+now>L) break;
        if(turn%2==0){
            sum+=now;
            leftcnt+=now;
        }else{
            sum+=now;
            rightcnt+=now;
        }
        
        turn++;
        now*=2;
        
        if(sum+now>L) break;
    }
    
    ll ans=0;
    
    ans+=(1+2*leftcnt-1)%mod*(leftcnt%mod)%mod*rui(2,mod-2);
    ans%=mod;
    
    ans+=(1+rightcnt)%mod*(rightcnt%mod)%mod;
    ans%=mod;
    
    if(turn%2==0){
        ans+=(2*(leftcnt%mod+1)-1+2*(leftcnt%mod+L%mod-sum%mod)-1+mod)%mod*((L-sum)%mod)%mod*rui(2,mod-2);
        ans%=mod;
    }else{
        ans+=(rightcnt%mod+1+rightcnt%mod+L%mod-sum%mod+mod)%mod*((L-sum)%mod)%mod;
        ans%=mod;
    }
    
    //cout<<ans<<endl;
    
    ans=mod-ans;
    
    swap(L,R);
    
    now=1;sum=0;leftcnt=0;rightcnt=0;turn=0;
    
    while(1){
        if(sum+now>L) break;
        if(turn%2==0){
            sum+=now;
            leftcnt+=now;
        }else{
            sum+=now;
            rightcnt+=now;
        }
        
        turn++;
        now*=2;
        
        if(sum+now>L) break;
    }
    
    ans+=(1+2*leftcnt-1)%mod*(leftcnt%mod)%mod*rui(2,mod-2);
    ans%=mod;
    
    ans+=(1+rightcnt)%mod*(rightcnt%mod)%mod;
    ans%=mod;
    
    if(turn%2==0){
        ans+=(2*(leftcnt%mod+1)-1+2*(leftcnt%mod+L%mod-sum%mod)-1+mod)%mod*((L-sum)%mod)%mod*rui(2,mod-2);
        ans%=mod;
    }else{
        ans+=(rightcnt%mod+1+rightcnt%mod+L%mod-sum%mod+mod)%mod*((L-sum)%mod)%mod;
        ans%=mod;
    }
    
    cout<<ans<<endl;
}