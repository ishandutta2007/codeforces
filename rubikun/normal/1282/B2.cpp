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
        ll N,P,K;cin>>N>>P>>K;
        vector<ll> A(N),sum(N+1),sumk(N+2);
        for(int i=0;i<N;i++) cin>>A[i];
        sort(all(A));
        
        sum[0]=A[0];
        sumk[0]=A[0];
        for(int i=1;i<N;i++){
            sum[i]=sum[i-1]+A[i];
            if(i<K-1) sumk[i]=sum[i];
            else if(i==K-1) sumk[i]=A[i];
            else sumk[i]=sumk[i-K]+A[i];
        }
        sum[N]=INF;
        
        ll ans=0;
        
        for(int i=0;i<N;i++){
            if(sumk[i]<=P) ans=i+1;
        }
        
        cout<<ans<<endl;
    }
}