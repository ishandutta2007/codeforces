/*
ID: Sfiction
OJ: CF
PROB: 337E
*/
#include <cstdio>
#include <cmath>
#include <cstdlib>
struct node
{
    long long val,last;
    int fa;
};
const int MAXN=1000000;
int n;
int pri[120000],len;
char p[MAXN];
int ans;
node a[9];
int Comp(const void *a,const void *b)
{
    return ((node *)b)->val>((node *)a)->val?1:-1;
}
void Pre()
{
    int i,j;
    for (i=2;i<=MAXN;++i)
    {
        if (!p[i]) pri[len++]=i;
        for (j=0;j<len;++j)
        {
            if (pri[j]*i>MAXN) break;
            p[pri[j]*i]=1;
            if (i%pri[j]==0) break;
        }
    }
    pri[len]=1<<30;
}
int Divisor(long long x)
{
    long long t;
    int i,s;
    s=0;
    t=sqrt(x);
    for (i=0;x>1&&pri[i]<=t;++i)
        for (;x%pri[i]==0;++s) x/=pri[i];
    if (x>1) ++s;
    return s;
}
void Check()
{
    int i,t,tt;
    t=n;
    if (a[0].val>1) ++t;
    for (i=1;i<=n;++i)
    {
        tt=Divisor(a[i].last);
        if (tt>1||a[i].last<a[i].val) t+=tt;
    }
    if (t<ans) ans=t;
}
void DFS(int x)
{
    if (x>n)
    {
        Check();
        return;
    }
    int i;
    a[x].fa=0;
    ++a[0].val;
    DFS(x+1);
    --a[0].val;
    for (i=1;i<x;++i)
        if (a[i].last%a[x].val==0)
        {
            a[i].last/=a[x].val;
            a[x].fa=i;
            DFS(x+1);
            a[i].last*=a[x].val;
        }
}
int main()
{
    int i;
    Pre();
    ans=1<<30;
    scanf("%d",&n);
    for (i=1;i<=n;++i)
    {
        scanf("%I64d",&a[i].val);
        a[i].last=a[i].val;
    }
    qsort(a+1,n,sizeof(a[0]),Comp);
    DFS(1);
    printf("%d",ans);
    return 0;
}