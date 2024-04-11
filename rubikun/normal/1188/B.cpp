#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18;
const ll INF=1LL<<55;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    ll N,P,K;cin>>N>>P>>K;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    map<ll,int> M;
    ll ans=0;
    
    for(int i=0;i<N;i++){
        ll a=A[i]*(A[i]*A[i]%P*A[i]%P+P-K)%P;
        M[a]++;
        if(M[a]>=2){
            ans-=(M[a]-1)*(M[a]-2)/2;
            ans+=M[a]*(M[a]-1)/2;
        }
    }
    
    cout<<ans<<endl;
    
    
}