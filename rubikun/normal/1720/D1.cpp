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
const int mod=998244353,MAX=305,INF=1<<30;

int dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        int ans=0;
        for(int q=0;q<N;q+=256){
            vector<int> B;
            for(int i=q;i<min(q+256,N);i++) B.push_back(A[i]);
            for(int i=0;i<si(B);i++) dp[i]=-INF;
            for(int i=0;i<si(B);i++){
                dp[i]=1;
                for(int j=0;j<i;j++){
                    if((B[j]^i)<(j^B[i])) chmax(dp[i],dp[j]+1);
                }
            }
            for(int i=0;i<si(B);i++) chmax(ans,dp[i]);
        }
        cout<<ans<<"\n";
    }
}