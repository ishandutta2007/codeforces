#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N+2),left(N+2),right(N+2);
    for(int i=0;i<N;i++) cin>>A[i+1];
    A[N+1]=INF;
    
    for(int i=1;i<N+1;i++){
        if(A[i-1]<A[i]){
            left[i]=left[i-1]+1;
        }else left[i]=1;
    }
    
    for(int i=N;i>=1;i--){
        if(A[i]<A[i+1]){
            right[i]=right[i+1]+1;
        }else right[i]=1;
    }
    
    int ans=0;
    
    for(int i=1;i<=N;i++) ans=max(ans,left[i]);
    
    for(int i=1;i<=N;i++){
        if(A[i-1]<A[i+1]) ans=max(ans,left[i-1]+right[i+1]);
    }
    
    cout<<ans<<endl;
}