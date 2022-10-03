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
const int mod=1000000007,MAX=1000005;
const ll INF=1LL<<60;

ll dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,r1,r2,r3,d;cin>>N>>r1>>r2>>r3>>d;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    for(int i=0;i<MAX;i++) dp[i]=INF;
    
    dp[0]=0;
    
    for(int i=0;i<N;i++){
        if(i+1<N){
            chmin(dp[i+2],dp[i]+min((A[i]+1)*r1,r2)+min((A[i+1]+1)*r1,r2)+r1+r1+3*d+(i+1!=N-1)*d);
            
            chmin(dp[i+2],dp[i]+min((A[i]+1)*r1,r2)+(A[i+1]*r1+r3)+r1+2*d+(2*(i+1!=N-1))*d);
        }
        
        chmin(dp[i+1],dp[i]+(A[i]*r1+r3)+(i!=N-1)*d);
        chmin(dp[i+1],dp[i]+min((A[i]+1)*r1,r2)+r1+2*d+(i!=N-1)*d);
    }
    
    cout<<dp[N]<<endl;
}