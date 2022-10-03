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
const int mod=1000000007,MAX=2005,INF=1<<30;
int dp[MAX][4];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=1;i<MAX;i++) for(int j=0;j<4;j++) dp[i][j]=-INF;
    for(int i=0;i<N;i++){
        for(int j=0;j<4;j++){
            chmax(dp[i+1][j],dp[i][j]);
            if(A[i]==1){
                if(j%2==0) dp[i+1][j]++;
            }else{
                if(j%2==1) dp[i+1][j]++;
            }
        }
        for(int j=1;j<4;j++) chmax(dp[i+1][j],dp[i+1][j-1]);
    }
    
    int ans=0;
    for(int j=0;j<4;j++) chmax(ans,dp[N][j]);
    
    cout<<ans<<endl;
}