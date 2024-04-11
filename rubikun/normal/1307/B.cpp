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
        int N;
        ll X;cin>>N>>X;
        vector<ll> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        sort(all(A));
        
        if(A[N-1]>=X){
            bool ok=false;
            
            for(int i=0;i<N;i++){
                if(A[i]==X) ok=true;
            }
            
            if(ok) cout<<1<<endl;
            else cout<<2<<endl;
        }else{
            cout<<(X+A[N-1]-1)/A[N-1]<<endl;
        }
    }
}