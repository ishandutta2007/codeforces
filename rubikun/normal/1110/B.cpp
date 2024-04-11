#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100003,INF=1<<30;

int main(){
    
    int N,M,K;cin>>N>>M>>K;
    int ans=N;
    vector<int> A(N),B;
    
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    for(int i=1;i<N;i++){
        B.push_back(A[i]-A[i-1]-1);
    }
    
    sort(all(B));
    
    for(int i=0;i<N-K;i++) ans+=B[i];
    
    cout<<ans<<endl;
}