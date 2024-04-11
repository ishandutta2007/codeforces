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
    
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<ll> A(N+2),left(N+2),right(N+2);
        for(int i=0;i<N;i++){
            cin>>A[i+1];
        }
        
        for(int i=1;i<N+2;i++) left[i]+=A[i]+left[i-1];
        for(int i=N;i>=0;i--) right[i]+=A[i]+right[i+1];
        
        bool ok=true;
        
        for(int i=1;i<N;i++) if(left[i]<=0) ok=false;
        for(int i=N;i>=2;i--) if(right[i]<=0) ok=false;
        
        //for(int i=1;i<N;i++) cout<<left[i]<<endl;
        
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
        
    }
    
}