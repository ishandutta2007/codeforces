#include <cstdio>
#include <cstring>
#define maxn 200005
#define maxb 200005
#define mod 1000000007
using namespace std;
int n,i,j,u,v,ind;
int to[maxn];
int dfn[maxn],low[maxn],belong[maxn],bsize[maxb],binv[maxb],btot;
bool ins[maxn];
int stk[maxn],sttop;
long long ans,fac[maxn],fac_inv[maxn];
void addedge(int u,int v)
{
    to[u]=v;
}
void tarjan(int i)
{
    int j;
    ind++;
    dfn[i]=low[i]=ind;
    ins[i]=1;
    stk[++sttop]=i;
    if (dfn[to[i]]==0)
    {
        tarjan(to[i]);
        if (low[to[i]]<low[i])
            low[i]=low[to[i]];
    }
    else
        if (ins[to[i]]&&dfn[to[i]]<low[i])
            low[i]=dfn[to[i]];
    if (dfn[i]==low[i])
    {
        btot++;
        j=0;
        while (j!=i&&sttop)
        {
            j=stk[sttop];
            ins[j]=0;
            belong[j]=btot;
            sttop--;
            bsize[btot]++;
            binv[btot]=j;
        }
    }
}
long long qpow(long long base,long long p)
{
    if (p==0)
        return 1;
    long long t=qpow(base,p>>1);
    t=t*t%mod;
    if (p&1)
        t=t*base%mod;
    return t;
}
long long get(int u)
{
    long long ret=0;
    for (int i=1;i<=u-1;i++)
        ret=(ret+fac[u]*fac_inv[i]%mod*fac_inv[u-i]%mod)%mod;
    return ret;
}
int main()
{
    scanf("%d",&n);
    fac[0]=fac[1]=1;
    for (i=2;i<=n;i++)
        fac[i]=(fac[i-1]*i)%mod;
    for (i=0;i<=n;i++)
        fac_inv[i]=qpow(fac[i],mod-2);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&v);
        addedge(i,v);
    }
    for (i=1;i<=n;i++)
        if (!dfn[i])
            tarjan(i);
    ans=1;
    for (i=1;i<=btot;i++)
        if (bsize[i]>1)
            ans=(ans*get(bsize[i]))%mod;
        else
            if (to[binv[i]]==binv[i])
                ans*=0;
            else
                ans=ans*2%mod;
    printf("%I64d\n",ans);
    return 0;
}