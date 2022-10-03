#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=5005,INF=1<<29;

int dp[MAX][MAX][2];
vector<int> A;
int N;

int solve(int l,int r,bool wh){
    if(dp[l][r][wh]<INF) return dp[l][r][wh];
    
    if(r-l==1){
        dp[l][r][0]=dp[l][r][1]=0;
        return 0;
    }
    
    if(wh==0){
        int res=INF;
        res=min(res,solve(l+1,r,0)+1);
        res=min(res,solve(l+1,r,1)+(A[l]!=A[r-1]));
        
        return dp[l][r][wh]=res;
    }else{
        int res=INF;
        res=min(res,solve(l,r-1,0)+(A[l]!=A[r-1]));
        res=min(res,solve(l,r-1,1)+1);
        
        return dp[l][r][wh]=res;
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N;i++){
        int a;cin>>a;
        if(A.size()==0||A.back()!=a) A.push_back(a);
    }
    
    for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) dp[i][j][0]=dp[i][j][1]=INF;
    
    N=A.size();
    
    cout<<min(solve(0,N,0),solve(0,N,1))<<endl;
}