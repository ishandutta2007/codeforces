#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,MAX_LOG=20,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,K;cin>>N>>K;
    vector<ll> A(N);
    vector<ll> S(N+1);
    for(int i=0;i<N;i++) cin>>A[i];
    sort(all(A));
    ll ans=1LL<<60;
    
    for(int i=1;i<=N;i++) S[i]=S[i-1]+A[i-1];
    
    for(ll i=0;i<N;){
        ll to=i;
        while(to<N&&A[to]==A[i]) to++;
        if(to-i>=K){
            cout<<0<<endl;
            return 0;
        }
        i=to;
    }
    
    for(ll i=0;i<N;){
        ll to=i;
        ll cnt=1LL<<60;
        while(to<N&&A[to]==A[i]) to++;
        
        //cout<<i<<" "<<to<<endl;
        
        if(to>=K){
            cnt=min(cnt,(A[i]-1)*i-S[i]+K-(to-i));
        }else{
            cnt=min(cnt,(A[i]-1)*i-S[i]+S[N]-S[to]-(A[i]+1)*(N-to)+K-(to-i));
        }
        
        if(N-i>=K){
            cnt=min(cnt,S[N]-S[to]-(A[i]+1)*(N-to)+K-(to-i));
        }
        
        ans=min(ans,cnt);
        i=to;
        
        //cout<<ans<<endl;
    }
    
    cout<<ans<<endl;
}