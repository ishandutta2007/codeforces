#include<stdio.h>
#include<cstring>
#define MAXN 20005
using namespace std;
char p1[5005],p2[5005],pa[10005];
long lena,lenb,len;
struct sam
{
    long pre[MAXN*2],go[MAXN*2][28],step[MAXN*2],last,tot;
    long be[MAXN*2][2];
    void init()
    {
        memset(pre,0,sizeof pre);
        memset(go,0,sizeof go);
        memset(step,0,sizeof step);
        memset(be,0,sizeof be);
        last=tot=1;
    }
    void expended(long x)
    {
        long q=last,p,syc=++tot;
        step[syc]=step[q]+1;
        for(p=q;p&&!go[p][x];p=pre[p])go[p][x]=syc;
        if(!p)pre[syc]=1;
        else
        {
            long gt=go[p][x];
            if(step[gt]==step[p]+1)pre[syc]=gt;
            else
            {
                long qt=++tot;
                pre[qt]=pre[gt];
                pre[gt]=pre[syc]=qt;
                step[qt]=step[p]+1;
                memcpy(go[qt],go[gt],sizeof go[qt]);
                for(long z=p;z&&go[z][x]==gt;z=pre[z])go[z][x]=qt;
            }
        }
        last=syc;
    }
}mysam;
#define mstep mysam.step
#define mpre mysam.pre
#define mt mysam.tot
#define mgo mysam.go
#define mbe mysam.be
long top[MAXN*2],t[MAXN];
int main()
{
    scanf("%s",pa+1);
    lena=len=strlen(pa+1);
    scanf("%s",p1+1);
    lenb=strlen(p1+1);
    pa[++len]='z'+1;
    for(long i=1;i<=lenb;i++)pa[len+i]=p1[i];
    len+=lenb;mysam.init();
    for(long i=1;i<=len;i++)mysam.expended(pa[i]-'a'+1);
    for(long i=1;i<=mt;i++)t[mstep[i]]++;
    for(long i=1;i<=len;i++)t[i]+=t[i-1];
    for(long i=1;i<=mt;i++)top[t[mstep[i]]--]=i;
    for(long now=1,j=1;j<=len;j++)
    {
        now=mgo[now][pa[j]-'a'+1];
        if(j<=lena)mbe[now][0]++;
        else if(j>lena+1)mbe[now][1]++;
    }
    for(long i=mt;i>=1;i--)
    {
        long j=top[i];
        if(mpre[j])
        {
            mbe[mpre[j]][0]+=mbe[j][0];
            mbe[mpre[j]][1]+=mbe[j][1];
        }
    }
    long ans=0;
    for(long i=2;i<=mt;i++)
    if(mbe[i][0]==1&&mbe[i][1]==1)
    {
        if(mstep[mpre[i]]+1<ans||!ans)
        {
            ans=mstep[mpre[i]]+1;
        } 
    }
    if(!ans)printf("-1");else printf("%ld\n",ans);
    return 0;
}