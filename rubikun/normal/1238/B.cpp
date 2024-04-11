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
        int N,r;cin>>N>>r;
        vector<ll> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        sort(all(A));
        A.erase(unique(all(A)),A.end());
        
        int ans=A.size();
        for(int i=1;i<A.size();i++){
            if(A[i-1]<=(ll(A.size())-i)*r) ans=A.size()-i;
        }
        
        cout<<ans<<endl;
        
    }

}