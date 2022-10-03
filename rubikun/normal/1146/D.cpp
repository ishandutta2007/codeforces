#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll M;int A,B;cin>>M>>A>>B;
    ll ans=0,now=0;
    set<ll> SE;
    SE.insert(0);
    
    ll i;
    for(i=0;i<=M;i++){
        while(1){
            bool did=false;
            while(now+A<=i){
                now+=A;
                SE.insert(now);
                did=true;
            }
            while(now-B>=0){
                now-=B;
                SE.insert(now);
                did=true;
            }
            
            if(!did||now==0) break;
        }
        ans+=ll(SE.size());
        if(SE.size()>=2&&now==0) break;
    }
    i++;
    
    ll C=gcd(A,B);
    
    if(C==1){
        if(i<=M) ans+=(i+1+M+1)*(M-i+1)/2;
    }else{
        while(i%C!=0&&i<M){
            ans+=i/C+1;
            i++;
        }
        ll k;
        for(k=i;k+C-1<=M;k+=C){
            ans+=(k/C+1)*C;
        }
        if(k<=M) ans+=(k/C+1)*(M-k+1);
        
    }
    
    cout<<ans<<endl;
    
    
}