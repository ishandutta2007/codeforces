#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    
    while(Q--){
        int N;cin>>N;
        vector<ll> A(N+1),ma(N+1);
        for(int i=0;i<N;i++) cin>>A[i+1];
        ma[0]=-INF;
        
        for(int i=1;i<=N;i++){
            ma[i]=max(ma[i-1],A[i]);
        }
        
        ll ans=0;
        
        for(int i=1;i<=N;i++){
            ans=max(ans,ma[i-1]-A[i]);
        }
        
        for(int i=50;i>=0;i--){
            if(ans&(1LL<<i)){
                cout<<i+1<<"\n";
                break;
            }
        }
        
        if(ans==0) cout<<"0\n";
    }
}