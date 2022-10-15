#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,c[MAXN];
int dp[MAXN][MAXN][3][3],ndp[MAXN][MAXN][3][3];
int ans[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<26;i++) scanf("%d",&c[i]);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            int c1=(i==0?1:0)+(j==0?1:0);
            int c2=(i==1?1:0)+(j==1?1:0);
            int mult=1;
            if(i==2) mult=mult*24;
            if(j==2) mult=mult*24;
            dp[c1][c2][i][j]=mult;
        }
    for(int _=3;_<=n;_++)
    {
        memset(ndp,0,sizeof(ndp));
        for(int c1=0;c1<=_;c1++)
        {
            for(int c2=0;c2<=_;c2++)
            {
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            if(i!=2&&i==k) continue;
                            int nc1=c1+(k==0?1:0);
                            int nc2=c2+(k==1?1:0);
                            int coef=(k==2?(i==k?23:24):1);
                            add(ndp[nc1][nc2][j][k],1LL*coef*dp[c1][c2][i][j]%MOD); 
                        }
                    }
                }
            }
        }
        swap(dp,ndp);
    }
    memset(ans,0,sizeof(ans));
    for(int c1=0;c1<=n;c1++)
        for(int c2=0;c2<=n;c2++)
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    add(ans[c1][c2],dp[c1][c2][i][j]);
    int res=0;
    for(int i=0;i<=n;i++)
        for(int j=n;j>=0;j--)
            add(ans[i][j],ans[i][j+1]);
    for(int i=0;i<26;i++)
        for(int j=c[i]+1;j<=n;j++)
            dec(res,ans[j][0]);
    for(int i=0;i<=n;i++)
        for(int j=n;j>=0;j--)
            add(ans[j][i],ans[j+1][i]);
    add(res,ans[0][0]);
    for(int i=0;i<26;i++)
        for(int j=i+1;j<26;j++)
            add(res,ans[c[i]+1][c[j]+1]);
    printf("%d\n",res);
}