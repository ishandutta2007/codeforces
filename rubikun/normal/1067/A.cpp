#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100005,INF=1<<30;
ll dp[MAX][203][2];
ll sum[203][2];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    dp[0][1][1]=1;
    for(int i=1;i<=200;i++) sum[i][1]=1;
    
    for(int i=0;i<N;i++){
        for(int k=1;k<=200;k++){
            if(A[i]!=-1&&A[i]!=k) continue;
            
            dp[i+1][k][0]+=sum[k-1][0]+sum[k-1][1];
            
            dp[i+1][k][0]%=mod;
        }
        
        for(int k=1;k<=200;k++){
            if(A[i]!=-1&&A[i]!=k) continue;
            
            dp[i+1][k][1]+=sum[200][1]-sum[k-1][1]+mod+dp[i][k][0];
            
            dp[i+1][k][1]%=mod;
        }
        
        memset(sum,0,sizeof(sum));
        
        for(int k=1;k<=200;k++){
            sum[k][0]=sum[k-1][0]+dp[i+1][k][0];
            sum[k][1]=sum[k-1][1]+dp[i+1][k][1];
            
            sum[k][0]%=mod;
            sum[k][1]%=mod;
        }
    }
    
    cout<<sum[200][1]<<endl;
}