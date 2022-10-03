#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,K;cin>>N>>K;
    vector<ll> A(N),diff(N-1);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<N-1;i++){
        diff[i]=A[i+1]-A[i];
    }
    
    sort(all(diff));
    
    ll ans=0;
    
    for(int i=0;i<N-K;i++){
        ans+=diff[i];
    }
    
    cout<<ans<<endl;
}