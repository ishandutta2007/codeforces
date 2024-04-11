#include <iostream>
#include <cstdio>
#include <climits>
#define MIN -(1ll<<61)
using namespace std;

int X,Y;
long long int G[1505][1505],A[1505][1505],dp[1505][1505],tmp;

int main(){
    scanf("%d%d",&X,&Y);
    for(int i=1;i<=X;++i)
        for(int j=1;j<=Y;++j){
            scanf("%I64d",&G[i][j]);
            A[i][j] = G[i][j] + A[i][j-1];
        }
    for(int j=1;j<=Y;++j){
        dp[1][j] = A[1][j];
//      printf("dp[%d][%d] = %lld\n",1,j,dp[1][j]);
    }
    for(int i=2;i<=X;++i){
        tmp = MIN;
        if( (i&1ll) == 0){
            dp[i][Y]=tmp;
            for(int j=Y-1;j>0;--j){
                tmp = max(tmp,dp[i-1][j+1]);
                dp[i][j] = A[i][j]+tmp;
    //          printf("dp[%d][%d] = %lld\n",i,j,dp[i][j]);
            }
        }
        else{
            dp[i][1]=tmp;
            for(int j=2;j<=Y;++j){
                tmp = max(tmp,dp[i-1][j-1]);
                dp[i][j] = A[i][j]+tmp;
        //      printf("dp[%d][%d] = %lld\n",i,j,dp[i][j]);
            }
        }
    }
    tmp = MIN;
    for(int j=1;j<=Y;++j) tmp = max(tmp,dp[X][j]);
    printf("%I64d\n",tmp);
//  system("pause");
    return 0;
}