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
const int mod=1000000007,MAX=30005;
const int INF=1<<30;
//const ll INF=1LL<<60;

int dp[MAX][2005];
int score[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,D;cin>>N>>D;
    
    for(int i=0;i<N;i++){
        int a;cin>>a;
        score[a]++;
    }
    
    for(int i=0;i<MAX;i++) for(int j=0;j<2005;j++) dp[i][j]=-INF;
    dp[D][1000]=score[D];
    
    for(int i=D+1;i<=30000;i++){
        for(int j=2;j<=1998;j++){
            int l=D+j-1000;
            for(int k=-1;k<=1;k++){
                if(l>0&&i-l>=D&&dp[i-l][j+k]>=0){
                    chmax(dp[i][j],dp[i-l][j+k]+score[i]);
                    //if(dp[i][j]>=0) cout<<i<<" "<<j<<" "<<i-x<<" "<<j-k<<" "<<l<<" "<<k<<endl;
                }
            }
            //if(dp[i][j]>=0) cout<<i<<" "<<j<<endl;
        }
    }
    
    int ans=0;
    
    for(int i=0;i<MAX;i++) for(int j=0;j<2005;j++) chmax(ans,dp[i][j]);
    
    cout<<ans<<endl;
}