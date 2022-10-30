#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <algorithm>
#define mk make_pair
using namespace std;

map < pair<int,int> , int> H;

int n,i,j,k,l,p,q;
int x[100005],y[100005];
int son[100005][5],fa[100005][5];
int ns[100005],nf[100005];
int Min[400005],Max[400005];
int ans[100005];
long long Ans;
bool del[100005];

void work(int x)
{
    int i;
    for(i=l+x-1>>1;i;i>>=1)Min[i]=min(Min[i<<1],Min[i<<1|1]);
    for(i=l+x-1>>1;i;i>>=1)Max[i]=max(Max[i<<1],Max[i<<1|1]);
}

void check(int x)
{
    if(del[x])return;
    int i=l+x-1;
    if(ns[x])Min[i]=200000,Max[i]=-200000;else Min[i]=Max[i]=x;
    work(x);
}

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d%d",&x[i],&y[i]);
        H[mk(x[i],y[i])]=i;
    }
    for(l=1;l<n;l*=2);
    for(i=l+l;i;--i)Min[i]=200000,Max[i]=-200000;
    for(i=1;i<=n;++i)
    {
        for(j=-1;j<=1;++j)
        if(H.find(mk(x[i]+j,y[i]-1))!=H.end())
        fa[i][++fa[i][0]]=H[mk(x[i]+j,y[i]-1)];
        for(j=-1;j<=1;++j)
        if(H.find(mk(x[i]+j,y[i]+1))!=H.end())
        son[i][++son[i][0]]=H[mk(x[i]+j,y[i]+1)];
        nf[i]=fa[i][0];
    }
    for(i=1;i<=n;++i)
    if(nf[i]==1)
    for(j=fa[i][0];j;--j)
    ++ns[fa[i][j]];
    for(i=1;i<=n;++i)if(y[i]==0)nf[i]=100;
    for(i=1;i<=n;++i)check(i);
    for(q=1;q<=n;++q)
    {
        if(q&1)k=Max[1];else k=Min[1];
        del[k]=true;
        ans[q]=k-1;
        Min[l+k-1]=200000;
        Max[l+k-1]=-200000;
        work(k);
        if(nf[k]==1)
        {
            for(j=fa[k][0];j;--j)
            {
                --ns[fa[k][j]];
                check(fa[k][j]);
            }
        }
        for(i=son[k][0];i;--i)
        {
            p=son[k][i];
            --nf[p];
            if(nf[p]==1&&!del[p])
            for(j=fa[p][0];j;--j)
            {
                ++ns[fa[p][j]];
                check(fa[p][j]);
            }
        }
    }
    Ans=0;
    for(i=1;i<=n;++i)Ans=(Ans*n+ans[i])%1000000009;
    printf("%I64d\n",Ans);
}