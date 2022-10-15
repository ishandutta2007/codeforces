#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define INV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],inva[MAXN];
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
int g[2][MAXN],prod[MAXN],invprod[MAXN],ans[MAXN];
int f(int i,int j)
{
    if(i+j-1>=n) return 0;
    return 1LL*prod[i+j-1]*invprod[i-1]%MOD;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n-1;i++) inva[i]=pow_mod(a[i],MOD-2);
    prod[0]=invprod[0]=1;
    for(int i=1;i<=n-1;i++)
    {
        prod[i]=1LL*prod[i-1]*a[i]%MOD;
        invprod[i]=pow_mod(prod[i],MOD-2);
    }
    ans[0]++;
    g[1][0]=1;
    for(int i=2;i<=n;i++)
    {
        int now=i&1,last=now^1;
        memset(g[now],0,sizeof(g[now]));
        for(int j=0;j<=2*n-2;j++)
        {
            if(!j) g[now][j]=1; else g[now][j]=g[last][j-1];
            if(j>1) add(g[now][j],1LL*(a[i-1]-1)*inva[i-1]%MOD*f(i-1,j-1)%MOD);
            add(ans[j],1LL*prod[i-1]*g[now][j]%MOD);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=0;i+j<=n;j++)
            add(ans[j],1LL*prod[i-1]*f(i,j)%MOD);
    for(int i=0;i<=2*n-2;i++) ans[i]=1LL*ans[i]*INV%MOD;
    for(int i=1;i<=2*n-2;i++) printf("%d ",ans[i]);
    return 0;
}