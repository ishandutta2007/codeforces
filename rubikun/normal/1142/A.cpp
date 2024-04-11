#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005;
const ll INF=1LL<<60;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,K,A,B;cin>>N>>K>>A>>B;
    
    ll mini=INF,maxi=-1;
    ll start=A;
    
    for(ll i=0;i<N;i++){
        ll goal=i*K+B;
        if(start<=goal){
            ll dis=goal-start;
            ll ans=N*K/gcd(N*K,dis);
            mini=min(mini,ans);
            maxi=max(maxi,ans);
            
            dis=N*K-(goal-start);
            ans=N*K/gcd(N*K,dis);
            mini=min(mini,ans);
            maxi=max(maxi,ans);
        }else{
            ll dis=N*K-(start-goal);
            ll ans=N*K/gcd(N*K,dis);
            mini=min(mini,ans);
            maxi=max(maxi,ans);
            
            dis=start-goal;
            ans=N*K/gcd(N*K,dis);
            mini=min(mini,ans);
            maxi=max(maxi,ans);
        }
        
        goal=(i+1)*K-B;
        if(start<=goal){
            ll dis=goal-start;
            ll ans=N*K/gcd(N*K,dis);
            mini=min(mini,ans);
            maxi=max(maxi,ans);
            
            dis=N*K-(goal-start);
            ans=N*K/gcd(N*K,dis);
            mini=min(mini,ans);
            maxi=max(maxi,ans);
        }else{
            ll dis=N*K-(start-goal);
            ll ans=N*K/gcd(N*K,dis);
            mini=min(mini,ans);
            maxi=max(maxi,ans);
            
            dis=start-goal;
            ans=N*K/gcd(N*K,dis);
            mini=min(mini,ans);
            maxi=max(maxi,ans);
        }
    }
    
    cout<<mini<<" "<<maxi<<endl;
}