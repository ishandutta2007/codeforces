#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    vector<int> A(N);
    vector<ll> sum(M,0);
    for(int i=0;i<N;i++){
        //cin>>A[i];
        scanf("%d",&A[i]);
    }
    
    sort(all(A));
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        ans+=sum[i%M];
        ans+=ll(A[i]);
        sum[i%M]+=ll(A[i]);
        
        if(i) cout<<" ";
        cout<<ans;
    }
    
    cout<<endl;
    
    
}