#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=505,INF=1<<25;

int dp[MAX][MAX],to[MAX][MAX];
int A[MAX];

int solve(int l,int r){
    if(dp[l][r]>=0) return dp[l][r];
    
    if(r-l<=1){
        to[l][r]=A[l];
        return dp[l][r]=r-l;
    }
    
    if(r-l==2){
        if(A[l]==A[r-1]){
            to[l][r]=A[l]+1;
            return dp[l][r]=1;
        }
        else return dp[l][r]=2;
    }
    
    int ma=r-l;
    
    if(solve(l+1,r)==1){
        if(to[l+1][r]==A[l]){
            to[l][r]=to[l+1][r]+1;
            return dp[l][r]=1;
        }else{
            ma=2;
        }
    }
    
    if(solve(l,r-1)==1){
        if(to[l][r-1]==A[r-1]){
            to[l][r]=to[l][r-1]+1;
            return dp[l][r]=1;
        }else{
            ma=2;
        }
    }
    
    for(int i=l+2;i<=r-2;i++){
        ma=min(ma,solve(l,i)+solve(i,r));
        if(dp[l][i]==1&&dp[i][r]==1&&to[l][i]==to[i][r]){
            ma=1;
            to[l][r]=to[l][i]+1;
        }
    }
    
    return dp[l][r]=ma;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    memset(dp,-1,sizeof(dp));
    
    for(int i=0;i<N;i++) cin>>A[i];
    
    cout<<solve(0,N)<<endl;
}