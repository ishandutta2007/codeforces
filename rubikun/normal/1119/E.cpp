#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=300003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    ll ans=0;
    int right=1;
    
    for(int i=0;i<N;i++){
        ans+=A[i]/3;
        A[i]%=3;
        
        if(A[i]){
            while(right<N&&A[right]<2) right++;
            if(right!=N){
                A[i]--;
                A[right]-=2;
                ans++;
            }
        }
        if(A[i]){
            while(right<N&&A[right]<2) right++;
            if(right!=N){
                A[i]--;
                A[right]-=2;
                ans++;
            }
        }
        
        if(i+1==right) right++;
    }
    
    cout<<ans<<endl;
    
}