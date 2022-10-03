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
        vector<int> A(N),B(N);
        int wh1=INF,wh2=INF;
        for(int i=0;i<N;i++){
            cin>>A[i];
            if(A[i]==1) wh1=min(wh1,i);
            if(A[i]==-1) wh2=min(wh2,i);
        }
        
        for(int i=0;i<N;i++) cin>>B[i];
        
        bool ok=true;
        
        for(int i=N-1;i>=0;i--){
            if(A[i]==B[i]) continue;
            
            if(A[i]>B[i]){
                if(wh2>=i) ok=false;
            }
            
            if(A[i]<B[i]){
                if(wh1>=i) ok=false;
            }
        }
        
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}