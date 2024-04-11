#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=1000001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int k=0;k<T;k++){
        int N,K;cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        int mini=INF,ans;
        for(int i=0;i+K<N;i++){
            if(A[i+K]-A[i]<mini){
                mini=A[i+K]-A[i];
                ans=(A[i]+A[i+K])/2;
            }
        }
        cout<<ans<<endl;
    }
}