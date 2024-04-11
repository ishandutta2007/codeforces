#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<19,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,K;cin>>N>>K;
    vector<int> A(K),fi(N,INF),la(N,-INF);
    for(int i=0;i<K;i++){
        //cin>>A[i];
        scanf("%d",&A[i]);
        
        A[i]--;
        fi[A[i]]=min(fi[A[i]],i);
        la[A[i]]=max(la[A[i]],i);
    }
    
    int ans=0;
    
    for(int i=0;i<N;i++){
        if(i-1>=0) ans+=(fi[i]>la[i-1]);
        ans+=(fi[i]==INF);
        if(i+1<N) ans+=(fi[i]>la[i+1]);
        
        //cout<<ans<<endl;
    }
    
    cout<<ans<<endl;
    
    
}