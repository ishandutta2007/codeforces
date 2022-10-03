#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,K,M;cin>>N>>K>>M;
    vector<ll> A(N+1);
    for(int i=0;i<N;i++) cin>>A[i];
    sort(all(A));
    
    for(int i=1;i<=N;i++) A[i]+=A[i-1];
    
    double ans=0.0;
    
    for(ll i=N;i>=1;i--){
        ll rem=M-(i-1);
        if(rem<0) continue;
        
        ll can=min((N+1-i)*K,rem);
        chmax(ans,double(A[N]-A[i-1]+can)/double((N+1-i)));
    }
    
    cout<<setprecision(25)<<ans<<endl;
}