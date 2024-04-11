#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char s[MAXN],t[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int dp[MAXN][MAXN];
int main()
{
    scanf("%s",s+1); n=strlen(s+1); 
    scanf("%s",t+1); m=strlen(t+1);
    for(int j=m+1;j<=n;j++) t[j]='*';
    for(int j=1;j<=n;j++) if(s[1]==t[j]||t[j]=='*') dp[1][j]=2;
    for(int i=1;i<n;i++)
        for(int j=i;j<=n;j++)
        {
            if(!dp[i][j]) continue;
            if(s[i+1]==t[j-i]||t[j-i]=='*') add(dp[i+1][j],dp[i][j]);
            if(s[i+1]==t[j+1]||t[j+1]=='*') add(dp[i+1][j+1],dp[i][j]);
        }
    int ans=0;
    for(int i=m;i<=n;i++) add(ans,dp[i][i]);
    printf("%d\n",ans);
}