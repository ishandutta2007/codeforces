#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    vector<ll> wh;
    
    ll su=0;
    
    for(int i=0;i<N;i++){
        if(A[i]>=N-K+1){
            su+=A[i];
            wh.push_back(i);
        }
    }
    
    ll ans=1;
    
    for(int i=0;i+1<wh.size();i++){
        ans*=ll(wh[i+1]-wh[i]);
        ans%=mod;
    }
    
    cout<<su<<" "<<ans<<endl;
}