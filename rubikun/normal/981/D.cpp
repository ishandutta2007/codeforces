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
const int mod=1000000007,MAX=55,INF=1<<30;
bool dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    ll S=0;
    
    for(int k=61;k>=0;k--){
        S+=(1LL<<k);
        memset(dp,0,sizeof(dp));
        dp[0][0]=true;
        for(int i=0;i<N;i++){
            ll sum=0;
            for(int to=i;to<N;to++){
                sum+=A[to];
                if((sum&S)==S){
                    for(int j=0;j<K;j++) dp[to+1][j+1]|=dp[i][j];
                }
            }
        }
        
        if(!dp[N][K]) S-=(1LL<<k);
    }
    
    cout<<S<<endl;
}