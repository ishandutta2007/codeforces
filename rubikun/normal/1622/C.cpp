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
const int mod=1000000007,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;ll K;cin>>N>>K;
        vector<ll> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        sort(all(A));
        vector<ll> rui(N+1);
        for(int i=1;i<=N;i++){
            rui[i]=rui[i-1]+A[i-1];
        }
        ll X=A[0];
        ll ans=1LL<<60;
        if(rui.back()<=K){
            cout<<0<<"\n";
            continue;
        }
        
        for(int i=1;i<=N;i++){
            ll need=X-(K-(rui[i]-rui[1]))/(N+1-i);
            ll mi=1LL<<60;
            for(ll t=need-4;t<=need+4;t++){
                if((X-t)*(N+1-i)+rui[i]-rui[1]<=K) chmin(mi,t);
            }
            chmax(mi,0LL);
            chmin(ans,mi+N-i);
        }
        
        cout<<ans<<"\n";
    }
}