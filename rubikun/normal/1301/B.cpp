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
        vector<ll> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        
        ll ma=-INF,mi=INF;
        
        for(int i=0;i<N;i++){
            if(A[i]==-1){
                if(i){
                    if(A[i-1]!=-1){
                        ma=max(ma,A[i-1]);
                        mi=min(mi,A[i-1]);
                    }
                }
                if(i!=N-1){
                    if(A[i+1]!=-1){
                        ma=max(ma,A[i+1]);
                        mi=min(mi,A[i+1]);
                    }
                }
            }
        }
        
        ll an=0;
        
        for(int i=0;i+1<N;i++){
            if(A[i]!=-1&&A[i+1]!=-1) an=max(an,abs(A[i+1]-A[i]));
        }
        
        if(ma==-INF){
            cout<<0<<" "<<0<<endl;
        }else{
            cout<<max(an,(ma-mi+1)/2)<<" "<<(ma+mi+1)/2<<endl;
        }
    }
    
}