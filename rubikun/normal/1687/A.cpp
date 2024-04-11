#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N,K;cin>>N>>K;
        vector<ll> A(N+1);
        for(int i=1;i<=N;i++){
            ll x;cin>>x;
            A[i]=A[i-1]+x;
        }
        if(K>=N){
            ll ans=A.back();
            ans+=(K-1+K-N)*N/2;
            cout<<ans<<"\n";
        }else{
            ll ans=-1;
            for(int i=K;i<=N;i++){
                chmax(ans,A[i]-A[i-K]);
            }
            ans+=(K-1+0)*K/2;
            cout<<ans<<"\n";
        }
    }
}