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
const int mod=998244353,MAX=3005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N,A,B;cin>>N>>A>>B;
        vector<ll> X(N+1),rui(N+2);
        for(int i=1;i<=N;i++) cin>>X[i];
        for(int i=N;i>=0;i--) rui[i]=rui[i+1]+X[i];
        
        ll ans=1LL<<62;
        for(int k=0;k<=N;k++){
            chmin(ans,A*X[k]+B*(rui[k+1]-(N-k)*X[k]+X[k]));
        }
        cout<<ans<<"\n";
    }
}