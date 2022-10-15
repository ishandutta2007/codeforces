#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int h,w,n;
bool row[MAXN],col[MAXN];
int dp1[MAXN][MAXN],dp2[MAXN][MAXN];
int fact[MAXN],invf[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=5000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[5000]=pow_mod(fact[5000],MOD-2);
    for(int i=4999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d%d",&h,&w,&n);
    memset(row,true,sizeof(row));
    memset(col,true,sizeof(col));
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        int r1,c1,r2,c2;
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        row[r1]=row[r2]=false;
        col[c1]=col[c2]=false;
    }
    for(int i=1;i<=h;i++) if(row[i]) cnt1++;
    for(int i=1;i<=w;i++) if(col[i]) cnt2++;
    dp1[0][0]=1;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<=h;j++)
        {
            if(!dp1[i][j]) continue;
            add(dp1[i+1][j],dp1[i][j]);
            if(row[i+1]&&row[i+2]) add(dp1[i+2][j+1],dp1[i][j]);
        }
    }
    dp2[0][0]=1;
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(!dp2[i][j]) continue;
            add(dp2[i+1][j],dp2[i][j]);
            if(col[i+1]&&col[i+2]) add(dp2[i+2][j+1],dp2[i][j]);
        }
    }
    int ans=0;
    for(int i=0;i<=h;i++)
        for(int j=0;j<=w;j++)
        {
            if(dp1[h][i]&&dp2[w][j])
            {
                int res=1LL*dp1[h][i]*dp2[w][j]%MOD*comb(cnt1-2*i,j)%MOD*comb(cnt2-2*j,i)%MOD*fact[i]%MOD*fact[j]%MOD;
                add(ans,res);
            }
        }
    printf("%d\n",ans);
    return 0;
}