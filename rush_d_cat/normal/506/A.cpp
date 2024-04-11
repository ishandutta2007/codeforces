#include <iostream>
#include <map>
using namespace std;

int n, d;
int p[60000+10], ok[60000+10];
//map<int, int> dp[30000+10];
int dp[30000+10][600+10];
int main() 
{
    scanf("%d %d", &n, &d);
    
    int mx = -1;
    for(int i=1;i<=n;i++) {
        scanf("%d", &p[i]);
        ok[p[i]] ++;
        mx = max(mx, p[i]);
    }
        
    int ans = ok[d];

    for(int i=0;i<30000;i++) for(int j=0;j<600;j++) 
        dp[i][j] = -1e9;
    
    dp[d][280] = ok[d];

    for(int i = d+1; i <= mx; i++) 
    {
        for(int j = max(1, d - 280); j <= min(i, d + 280); j++) 
        {
            int sup = d - 280;

            dp[i][j - sup] = max(dp[i][j - sup], dp[i-j][j - sup] + ok[i]);
        
            dp[i][j - sup] = max(dp[i][j - sup], dp[i-j][j+1 - sup] + ok[i]);
            
            if(j-1 - sup > 0)
            dp[i][j - sup] = max(dp[i][j - sup], dp[i-j][j-1 - sup] + ok[i]);

            ans = max(ans, dp[i][j - sup]);
        }
    }

    printf("%d\n", ans);
}