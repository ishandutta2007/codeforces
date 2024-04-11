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
const int mod=1000000007,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    int Q;cin>>Q;
    while(Q--){
        int N;ll x;cin>>N>>x;
        vector<ll> A(N),rui(N+1),ma(N+1,-INF);
        for(int i=0;i<N;i++){
            cin>>A[i];
            rui[i+1]=rui[i]+A[i];
        }
        ma[0]=0;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<=N;j++){
                chmax(ma[j-i],rui[j]-rui[i]);
            }
        }
        for(int k=0;k<=N;k++){
            ll ans=0;
            for(int len=1;len<=N;len++){
                chmax(ans,ma[len]+min(len,k)*x);
                chmax(ans,ma[len]+max(0,k-(N-len))*x);
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
}