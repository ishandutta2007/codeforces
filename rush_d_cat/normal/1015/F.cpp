#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1e9+7;
const int N = 202;
int n,dp[N][N][N];
char s[N]; int slen;
int fail[N][2],nex[N];

void getFail() {
    int j=0;
    nex[0] = nex[1] = 0;
    for(int i=1;i<slen;i++) {
        while(j>0 && s[i]!=s[j]) j=nex[j];
        if(s[i]==s[j]) j++;
        nex[i+1] = j;
    }
    //printf("len = %d\n", slen);
    if (s[0] == '(') fail[0][0] = 1;
    if (s[0] == ')') fail[0][1] = 1;
    for(int i=1;i<=slen;i++) {
        int pos=i;
        while(pos && s[pos]!='(') pos=nex[pos];
        fail[i][0] = pos+1;
        if(pos==0&&s[0]==')') fail[i][0]=0;
        
        pos = i;
        while(pos && s[pos]!=')') pos=nex[pos];
        fail[i][1] = pos+1;
        if(pos==0&&s[0]=='(') fail[i][1]=0;

        //printf("i=%d %d %d\n", i,fail[i][0],fail[i][1]);
    }
}

int main() {
    scanf("%d%s", &n, s);
    slen = strlen(s);
    getFail();
    dp[0][0][0]=1;
    for(int i=0;i<2*n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<slen;k++){
                if(s[k]=='(') 
                {
                    (dp[i+1][j+1][k+1] += dp[i][j][k]) %= MOD;
                    if(j) (dp[i+1][j-1][fail[k][1]] += dp[i][j][k]) %= MOD;
                } else
                if(s[k]==')')
                {
                    (dp[i+1][j+1][fail[k][0]] += dp[i][j][k]) %= MOD;
                    if(j) (dp[i+1][j-1][k+1] += dp[i][j][k]) %= MOD;
                } 
            }
            (dp[i+1][j+1][slen] += dp[i][j][slen]) %= MOD;
            if(j) (dp[i+1][j-1][slen] += dp[i][j][slen]) %= MOD;
        }
    }
    int ans=dp[2*n][0][slen];
    cout<<ans<<endl;
}