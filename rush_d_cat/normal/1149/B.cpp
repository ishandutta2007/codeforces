#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
const int N=100000+10;
int n,q;
char s[N];
int nex[N][26],dp[252][252][252],len[4];
char stk[4][N];
int main() {
    scanf("%d%d%s",&n,&q,s+1);
    for(int i=0;i<=250;i++){
        for(int j=0;j<=250;j++){
            for(int k=0;k<=250;k++){
                dp[i][j][k]=n+1;
            }
        }
    }
    dp[0][0][0]=0;

    int pos[26]; for(int i=0;i<26;i++) pos[i]=n+1, nex[n+1][i]=n+1;

    for(int i=n;i>=0;i--){
        for(int j=0;j<26;j++){
            nex[i][j]=pos[j];
        }
        pos[s[i]-'a']=i;
    }

    while(q--) {
        char op[2]; scanf("%s",op);
        if(op[0]=='+') {
            int x; char ch[2];
            scanf("%d%s",&x,ch);
            len[x]++; stk[x][len[x]] = ch[0];

            if(x==1) {
                for(int j=0;j<=len[2];j++){
                    for(int k=0;k<=len[3];k++){
                        dp[len[x]][j][k] = nex[dp[len[x]-1][j][k]][ch[0]-'a'];
                        if(j) dp[len[x]][j][k] = min(dp[len[x]][j][k], nex[dp[len[x]][j-1][k]][stk[2][j]-'a']);
                        if(k) dp[len[x]][j][k] = min(dp[len[x]][j][k], nex[dp[len[x]][j][k-1]][stk[3][k]-'a']);
                    }
                }
            }
            if(x==2) {
                for(int j=0;j<=len[1];j++){
                    for(int k=0;k<=len[3];k++){
                        dp[j][len[x]][k] = nex[dp[j][len[x]-1][k]][ch[0]-'a'];
                        if(j) dp[j][len[x]][k] = min(dp[j][len[x]][k], nex[dp[j-1][len[x]][k]][stk[1][j]-'a']);
                        if(k) dp[j][len[x]][k] = min(dp[j][len[x]][k], nex[dp[j][len[x]][k-1]][stk[3][k]-'a']);
                    }
                }
            }
            if(x==3) {
                for(int j=0;j<=len[1];j++){
                    for(int k=0;k<=len[2];k++){
                        dp[j][k][len[x]] = nex[dp[j][k][len[x]-1]][ch[0]-'a'];
                        if(j) dp[j][k][len[x]] = min(dp[j][k][len[x]], nex[dp[j-1][k][len[x]]][stk[1][j]-'a']);
                        if(k) dp[j][k][len[x]] = min(dp[j][k][len[x]], nex[dp[j][k-1][len[x]]][stk[2][k]-'a']);
                    }
                }
            }

        } else {
            int x; scanf("%d",&x); len[x]--;
        }
        //printf("# dp[%d][%d][%d] = %d\n", len[1],len[2],len[3],dp[len[1]][len[2]][len[3]]);
        //printf("!! %d\n", dp[1][1][0]);
        printf("%s\n", dp[len[1]][len[2]][len[3]] <= n ? "YES" : "NO");
    }
}