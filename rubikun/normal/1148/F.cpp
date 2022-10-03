#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000003,MAX=203,INF=1<<30;
vector<int> S[64];

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<ll> V(N),mask(N);
    ll sum=0;
    for(int i=0;i<N;i++){
        cin>>V[i]>>mask[i];
        sum+=V[i];
        int x=0;
        for(int j=0;j<63;j++){
            if(mask[i]&(1LL<<j)) x=j;
        }
        S[x].push_back(i);
    }
    
    if(sum<0){
        for(int i=0;i<N;i++) V[i]=-V[i];
        sum=-sum;
    }
    
    ll ans=0;
    
    for(int i=0;i<63;i++){
        ll sum=0;
        for(int j:S[i]){
            if(__builtin_popcountll(mask[j]&ans)%2==0) sum+=V[j];
            else sum-=V[j];
        }
        if(sum>0) ans|=(1LL<<i);
    }
    
    cout<<ans<<endl;
}