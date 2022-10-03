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
const int mod=1000000007,MAX=105,INF=1<<30;

int dp[MAX][3];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=1;i<=N;i++) for(int j=0;j<3;j++) dp[i][j]=INF;
    for(int i=0;i<N;i++){
        int x;cin>>x;
        for(int j=0;j<3;j++){
            if((x&1)&&(j!=1)) chmin(dp[i+1][1],dp[i][j]);
            if((x&2)&&(j!=2)) chmin(dp[i+1][2],dp[i][j]);
            chmin(dp[i+1][0],dp[i][j]+1);
        }
    }
    cout<<min({dp[N][0],dp[N][1],dp[N][2]})<<endl;
}