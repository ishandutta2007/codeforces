#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> A(N+1),B(N+1),C(N);
        ll sum=0;
        for(int i=0;i<N;i++){
            cin>>A[i]>>B[i];
            sum+=A[i];
        }
        A[N]=A[0];
        B[N]=B[0];
        
        for(int i=0;i<N;i++){
            C[i]=min(B[i],A[i+1]);
        }
        sort(all(C));
        for(int i=1;i<N;i++) sum-=C[i];
        cout<<sum<<"\n";
    }
}