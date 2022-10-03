#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

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
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int X;ll N;cin>>X>>N;
    int Y=X;
    vector<int> SE;
    for(int i=2;i*i<=X;i++){
        if(Y%i==0){
            SE.push_back(i);
            while(Y%i==0){
                Y/=i;
            }
        }
    }
    
    if(Y!=1) SE.push_back(Y);
    
    sort(all(SE));
    
    ll ans=1;
    
    for(int p:SE){
        ll M=N,sum=0;
        while(M){
            sum+=M/p;
            M/=p;
        }
        ans*=rui(p,sum);
        ans%=mod;
    }
    
    cout<<ans<<endl;
}