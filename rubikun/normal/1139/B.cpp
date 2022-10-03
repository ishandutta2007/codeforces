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
    
    int N;cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    ll ans=0,pre=INF;
    
    for(int i=N-1;i>=0;i--){
        if(A[i]<pre){
            ans+=A[i];
            pre=A[i];
        }else{
            ans+=max(0LL,pre-1);
            pre=max(0LL,pre-1);
        }
    }
    
    cout<<ans<<endl;
}