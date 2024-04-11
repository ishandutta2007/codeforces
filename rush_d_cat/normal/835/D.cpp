#include <iostream>
#include <cstring>
using namespace std;
const int NICO = 5002;
int dp[NICO][NICO], n, g[NICO][NICO], ans[NICO];
char s[NICO];

void init() {
    for(int i=2;i<=n;i++) {  
        if(s[i]==s[i-1]) {  
            g[i-1][i]=1;  dp[i-1][i] = 2;
        }         
    }         

    for(int i=1;i<=n;i++) {  
        g[i][i] = 1;   dp[i][i] = 1;
        for(int j=i-2;j>=1;j--) {  
            if(s[j]==s[i] && g[j+1][i-1]) {  
                g[j][i] = 1;  dp[j][i] = 1;
            }         
        }  
    }
}

int main() {

    scanf("%s", s+1); n = strlen(s+1);
    init();
    
    for(int i=1;i<=n;i++) {
        for(int j=i-2;j>=1;j--) {
            int mid = (i + j) >> 1; // [j, mid] [mid, i]
            if((i + j) % 2 == 0) mid --;

            if(dp[j][mid] && g[j][i]) {
                dp[j][i] = dp[j][mid] + 1;
            }
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            ans[dp[i][j]] ++;
        }
    }

    for(int i=n-1;i>=1;i--) {
        ans[i] = ans[i] + ans[i+1];
    }

    for(int i=1;i<=n;i++) {
        printf("%d ", ans[i]);
    }

}