#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,MOD;
int dp[MAXN][MAXN*MAXN];
int tmp[MAXN*MAXN];
int comb[MAXN][MAXN];
int fact[MAXN];
int f[MAXN],g[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
const int shift=125000;
int main()
{
    scanf("%d%d",&n,&MOD);
    if(MOD==1) {puts("0"); return 0;}
    fact[0]=1;
    for(int i=1;i<=500;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    dp[1][shift]=1; 
    for(int i=1;i<=500;i++)
    {
        for(int j=-i*(i-1)/2;j<=i*(i-1)/2;j++) add(dp[i][shift+j],dp[i][shift+j-1]);
        memset(tmp,0,sizeof(tmp));
        for(int j=-i*(i-1)/2;j<=i*(i-1)/2;j++)//add [0,i] inversions
        {
            add(tmp[shift+j],dp[i][shift+j]);
            dec(tmp[shift+j+i+1],dp[i][shift+j]);
        }
        for(int j=-(i+1)*(i)/2;j<=(i+1)*i/2;j++) add(tmp[shift+j],tmp[shift+j-1]);
        for(int j=-(i+1)*(i)/2;j<=(i+1)*i/2;j++) //add [-i,0] inversions
        {
            add(dp[i+1][shift+j-i],tmp[shift+j]);
            dec(dp[i+1][shift+j+1],tmp[shift+j]);
        }
    }
    comb[0][0]=1;
    for(int i=1;i<=500;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(int j=1;j<i;j++) 
        {
            comb[i][j]=comb[i-1][j-1];
            add(comb[i][j],comb[i-1][j]);
        }
    }
    for(int i=1;i<=500;i++)
        for(int j=-i*(i-1)/2;j<=i*(i-1)/2;j++)
            add(dp[i][shift+j],dp[i][shift+j-1]);
    for(int i=3;i<=500;i++)
    {
        for(int j=1;j<=i;j++)
            for(int k=j+1;k<=i;k++)
            {
                int inv=j-k;
                add(g[i],dp[i-1][shift+inv-1]);
            }
    }
    for(int i=3;i<=500;i++)
    {
        for(int j=0;j<=i-2;j++)
            add(f[i],1LL*comb[i][j]*fact[j]%MOD*g[i-j]%MOD);
    }
    printf("%d\n",f[n]);
    return 0;
}