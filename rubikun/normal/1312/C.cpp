#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=305,INF=1<<25;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;ll K;cin>>N>>K;
        vector<ll> A(N),cnt(70);
        for(int i=0;i<N;i++) cin>>A[i];
        
        for(int i=0;i<N;i++){
            int j=0;
            while(A[i]){
                cnt[j]+=A[i]%K;
                A[i]/=K;
                j++;
            }
        }
        
        bool ok=true;
        for(int i=0;i<70;i++){
            if(cnt[i]>=2) ok=false;
        }
        
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}