#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000003,MAX=200003,INF=1<<30;
int sum[MAX][3],dp[MAX][3];

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int A,B,C;cin>>A>>B>>C;
    for(int i=0;i<A;i++){
        int a;cin>>a;
        sum[a][0]++;
    }
    for(int i=0;i<B;i++){
        int a;cin>>a;
        sum[a][1]++;
    }
    for(int i=0;i<C;i++){
        int a;cin>>a;
        sum[a][2]++;
    }
    
    for(int j=0;j<3;j++){
        for(int i=1;i<MAX;i++){
            sum[i][j]+=sum[i-1][j];
        }
    }
    
    for(int i=0;i<MAX;i++){
        dp[i][0]=i-sum[i][0];
        dp[i][0]+=(-i)+sum[i][1];
    }
    
    for(int i=1;i<MAX;i++){
        dp[i][0]=min(dp[i][0],dp[i-1][0]);
    }
    
    for(int i=0;i<MAX;i++){
        dp[i][1]=i-sum[i][1]+dp[i][0];
    }
    
    int ans=INF;
    
    for(int i=0;i<=A+B+C;i++){
        ans=min(ans,dp[i][1]+(A+B+C-i)-(sum[A+B+C][2]-sum[i][2]));
    }
    
    cout<<ans<<endl;
    
}