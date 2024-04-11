#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    map<ll,ll> MA;
    for(ll i=1;i<=1000000;i++){
        MA[i*i*i]=i;
    }
    
    int Q;cin>>Q;
    while(Q--){
        ll a,b;cin>>a>>b;
        bool ans=true;
        if(MA.find(a*b)==MA.end()){
            ans=false;
        }else{
            ll c=MA[a*b];
            
            ll g=gcd(a,b);
            
            if(g%c) ans=false;
        }
        
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}