#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=200001,INF=1<<30;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    vector<ll> A(N),B(M);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<M;i++){
        cin>>B[i];
    }
    
    ll nowgcd=A[1]-A[0];
    
    for(int i=2;i<N;i++){
        nowgcd=gcd(nowgcd,A[i]-A[0]);
    }
    int ans=-1;
    for(int i=0;i<M;i++){
        if(nowgcd%B[i]==0) ans=i+1;
    }
    if(ans!=-1){
        cout<<"YES"<<endl;
        cout<<A[0]<<" "<<ans<<endl;
    }else cout<<"NO"<<endl;
    
    
}