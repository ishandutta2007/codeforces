#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N=50+10;

int n;
char s[N][N];


int dp[N][N][N][N]; int s1[N][N],s2[N][N];
int solve(int x1,int x2,int y1,int y2) {
    //printf("solve %d %d %d %d\n", x1,x2,y1,y2);
    if(x1>x2 || y1>y2) return 0;
    //printf("ok\n");
    if(dp[x1][x2][y1][y2] != -1) return dp[x1][x2][y1][y2];
    //printf("ok\n");
    int mn = 1e9;
    int tot=0;
    for(int mid=x1;mid<=x2;mid++){
        tot+=s2[mid][y2] - s2[mid][y1-1];
        if(s2[mid][y2] - s2[mid][y1-1] == 0) {
            mn = min(mn, solve(x1,mid-1,y1,y2) + solve(mid+1,x2,y1,y2));
        }
    }
    //printf("tot = %d\n", tot);
    if(tot==0) {
        //printf("%d %d %d %d, %d\n", x1,x2,y1,y2,dp[x1][x2][y1][y2]);
        return dp[x1][x2][y1][y2]=0;
    }
    for(int mid=y1;mid<=y2;mid++){
        if(s1[x2][mid] - s1[x1-1][mid] == 0) {
            //printf("####\n");
            mn = min(mn, solve(x1,x2,y1,mid-1) + solve(x1,x2,mid+1,y2));
        }   
    }

    dp[x1][x2][y1][y2] = min(mn, max(x2-x1+1,y2-y1+1));
    //printf("%d %d %d %d %d\n", x1,x2,y1,y2,dp[x1][x2][y1][y2]);
    return dp[x1][x2][y1][y2];
}


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int x=1;x<=n;x++)for(int y=1;y<=n;y++) dp[i][j][x][y]=-1;
    
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            s1[i][j]=s1[i-1][j] + (s[i][j] == '#' ? 1 : 0);
            s2[i][j]=s2[i][j-1] + (s[i][j] == '#' ? 1 : 0);
        }
    }
    printf("%d\n", solve(1,n,1,n));
}