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
    vector<ll> A(N),S(N+1);
    for(int i=0;i<N;i++){
        cin>>A[i];
        S[i+1]=S[i]+A[i];
    }
    
    ll ans=0,ma=0;
    map<ll,ll> MA;
    MA[0]=0;
    
    for(int i=1;i<=N;i++){
        if(A[i-1]==0){
            ma=i;
            MA[S[i]]=i;
            continue;
        }
        
        if(MA.count(S[i])){
            ma=max(ma,MA[S[i]]+1);
            ans+=i-ma;
        }else{
            ans+=i-ma;
        }
        
        MA[S[i]]=i;
    }
    
    cout<<ans<<endl;
}