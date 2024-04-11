
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include <iostream>
using namespace std;

int n, m, s[105], op[25], team[25];
int dp[1 << 20];
char ch;

int count(int x){ 
    return x == 0 ? 0 : (x & 1) + count (x >> 1);
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++) scanf("%d",&s[i]);
    sort(s + 1, s + 1 + n);
    scanf("%d",&m);
    for (int i = 0; i < m; i ++){
         scanf("\n%c%d",&ch,&team[i]);
         op[i] = (ch == 'p');
         //cout << op[i] << "\n";
    }
    
    dp[(1<<m)-1] = 0;
    for (int i = (1<<m)-2; i >= 0; i --){
        int cur = count(i);
        if (team[cur] == 1){
            dp[i] = -1e9;
            for (int j = 0; j < m; j ++)
                 if ((i & (1<<j)) == 0){
                        //cout << i << " " << dp[i | (1<<j)] + op[cur] * s[n - j] << " " << op[cur] << " " << s[n-j] << " " << "\n";
                      dp[i] = max(dp[i], dp[i | (1<<j)] + op[cur] * s[n - j]);
                 }
        }else{
            dp[i] = 1e9;
                 for (int j = 0; j < m; j ++)
                     if ((i & (1<<j)) == 0){
                            //cout << i << " " << dp[i | (1<<j)] - op[cur] * s[n - j] << " " << op[cur] << " " << s[n-j] << " " << "\n";
                         dp[i] = min(dp[i], dp[i | (1<<j)] - op[cur] * s[n-j]);
                     }
              }
    }
    
    //for (int i = 0; i < 16; i++)
   //     cout << i << " " << dp[i] << "\n";
    
    printf("%d\n",dp[0]);
    //system ("Pause");
    return 0;
}