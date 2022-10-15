#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char s[MAXN],t[MAXN];
int nxt[MAXN][26];
int T,n,m;
int dp[MAXN][MAXN],ndp[MAXN][MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1); scanf("%s",t+1);
        n=strlen(s+1); m=strlen(t+1);
        for(int i=0;i<26;i++) nxt[n+1][i]=n+1;
        for(int i=n;i>=1;i--)
        {
            for(int j=0;j<26;j++) nxt[i][j]=nxt[i+1][j];
            nxt[i][s[i]-'a']=i;
        }
        bool f=false;
        for(int len=0;len<=m-1;len++)
        {
            for(int i=0;i<=len;i++)
                for(int j=0;j<=m-len;j++)
                    dp[i][j]=n+1;
            dp[0][0]=0;
            for(int i=0;i<=len;i++)
            {
                for(int j=0;j<=m-len;j++)
                {
                    if(dp[i][j]==n+1) continue;
                    if(i<len) dp[i+1][j]=min(dp[i+1][j],nxt[dp[i][j]+1][t[i+1]-'a']);
                    if(j<m-len) dp[i][j+1]=min(dp[i][j+1],nxt[dp[i][j]+1][t[len+j+1]-'a']);
                }
            }
            if(dp[len][m-len]<n+1) f=true;
        }
        if(f) puts("YES"); else puts("NO");
    }
}