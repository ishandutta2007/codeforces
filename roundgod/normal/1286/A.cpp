#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int even,odd;
int dp[MAXN][MAXN][MAXN][2];
void upd(int &a,int b) {a=min(a,b);}
int main()
{
    scanf("%d",&n); 
    odd=(n+1)/2; even=n-odd;
    int last=-1,pos=0;
    int ans=0;
    for(int i=1;i<=n+1;i++) 
    {
        if(i<=n) scanf("%d",&a[i]);
        if(a[i])
        {
            if(a[i]&1) odd--; else even--;
        }
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=even;j++)
            for(int k=0;k<=odd;k++)
                dp[i][j][k][0]=dp[i][j][k][1]=INF;
    dp[0][even][odd][0]=dp[0][even][odd][1]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=even;j++)
        {
            for(int k=0;k<=odd;k++)
            {
                for(int l=0;l<2;l++)
                {
                    if(dp[i][j][k][l]==INF) continue;
                    if(a[i+1])
                    {
                        if(a[i+1]&1) upd(dp[i+1][j][k][1],dp[i][j][k][l]+((a[i+1]+l)&1));
                        else upd(dp[i+1][j][k][0],dp[i][j][k][l]+((a[i+1]+l)&1));
                    }
                    else
                    {
                        if(j) upd(dp[i+1][j-1][k][0],dp[i][j][k][l]+(l&1));
                        if(k) upd(dp[i+1][j][k-1][1],dp[i][j][k][l]+((l+1)&1));
                    }
                }
            }
        }
    }
    printf("%d\n",min(dp[n][0][0][0],dp[n][0][0][1]));
    return 0;
}