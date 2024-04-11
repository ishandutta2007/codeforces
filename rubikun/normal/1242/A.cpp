#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=1<<29;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    ll N;cin>>N;
    vector<ll> p;
    if(N==1){
        cout<<1<<endl;
        return 0;
    }
    ll M=N;
    
    for(ll i=2;i*i<=N;i++){
        if(M%i==0){
            p.push_back(i);
            while(M%i==0) M/=i;
        }
    }
    
    if(M!=1) p.push_back(M);
    
    if(p.size()==1){
        cout<<p[0]<<endl;
    }else{
        cout<<1<<endl;
    }
}