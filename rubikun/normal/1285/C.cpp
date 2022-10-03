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
    
    ll X;cin>>X;
    
    vector<ll> S;
    
    for(ll i=2;i*i<=X;i++){
        if(X%i!=0) continue;
        
        ll a=1;
        while(X%i==0){
            X/=i;
            a*=i;
        }
        
        S.push_back(a);
    }
    
    if(X!=1) S.push_back(X);
    
    sort(all(S));
    
    ll ans=(1LL)<<60;
    ll x=1,y=1;
    
    for(int bit=0;bit<(1<<int(S.size()));bit++){
        ll a=1,b=1;
        for(int i=0;i<S.size();i++){
            if(bit&(1<<i)) a*=S[i];
            else b*=S[i];
        }
        
        if(ans>max(a,b)){
            x=a;
            y=b;
            ans=max(a,b);
        }
    }
    
    cout<<x<<" "<<y<<endl;
}