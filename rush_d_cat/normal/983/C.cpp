#include <iostream>
#include <cstring>

using namespace std;
const int N = 20000+10;

int n;
int a[N],b[N];
int dp[2][12][10000+2];


void upd(int &x, int y) {
    x=min(x,y);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&a[i],&b[i]);
    }

    for(int i=0;i<2;i++)
        for(int j=0;j<=9;j++)
            for(int k=0;k<=9999;k++) dp[i][j][k]=1e9+7;


    dp[0][1][0]=0;
    int c[4];

    int flag=0;
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=9;j++) for(int k=0;k<=9999;k++) dp[(i+1)%2][j][k]=1e9+7;
        for(int k=9999;k>=0;k--) {
        for(int j=1;j<=9;j++) {
                // ijk
                c[0]=k%10;
                c[1]=k/10%10;
                c[2]=k/100%10;
                c[3]=k/1000%10; 

                // drop.
                if(c[0]) upd(dp[i%2][c[0]][k-c[0]], dp[i%2][j][k] + abs(j-c[0]) + 1); 
                if(c[1]) upd(dp[i%2][c[1]][k-c[1]*10], dp[i%2][j][k] + abs(j-c[1]) + 1); 
                if(c[2]) upd(dp[i%2][c[2]][k-c[2]*100], dp[i%2][j][k] + abs(j-c[2]) + 1); 
                if(c[3]) upd(dp[i%2][c[3]][k-c[3]*1000], dp[i%2][j][k] + abs(j-c[3]) + 1);                                 
                // get

                if (i == n) continue;
                if(c[0]==0||c[1]==0||c[2]==0||c[3]==0) {

                    if (c[0]==0)
                        upd(dp[(i+1)%2][a[i+1]][k+b[i+1]], dp[i%2][j][k]+abs(j-a[i+1])+1);
                    else if (c[1]==0)
                        upd(dp[(i+1)%2][a[i+1]][k+10*b[i+1]], dp[i%2][j][k]+abs(j-a[i+1])+1);
                    else if (c[2]==0)
                        upd(dp[(i+1)%2][a[i+1]][k+100*b[i+1]], dp[i%2][j][k]+abs(j-a[i+1])+1);
                    else if (c[3]==0)
                        upd(dp[(i+1)%2][a[i+1]][k+1000*b[i+1]], dp[i%2][j][k]+abs(j-a[i+1])+1);
                }
                

            }
        }
    }

    int ans=1e9+7;
    for(int i=1;i<=9;i++)
        ans=min(ans,dp[n%2][i][0]);
    cout<<ans<<endl;

}