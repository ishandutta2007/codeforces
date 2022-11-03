/*
ID: Sfiction
OJ: CF
PROB: 271B
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
const int MAX_Prime=101000,MAXN=500;
int row[MAXN],col[MAXN];
int pri[13000],len;
int find[MAX_Prime];
void Prime()
{
    char p[MAX_Prime];
    int i,j,N;
    memset(p,0,sizeof(p));
    N=sqrt(MAX_Prime);
    for (i=2;i<=N;++i)
        if (!p[i])
        {
            pri[len++]=i;
            for (j=i*i;j<MAX_Prime;j+=i) p[j]=1;
        }
    for (++i;i<MAX_Prime;++i)
        if (!p[i]) pri[len++]=i;
    return;
}
void Write()
{
    int i,j,t;
    t=0;
    for (i=0;i<len;t=j,++i)
        for (j=t;j<=pri[i];++j) find[j]=pri[i]-j;
    return;
}
int main()
{
    int N,M;
    int i,j,t,ans;
    Prime();
    Write();
    scanf("%d%d",&N,&M);
    for (i=0;i<N;++i)
        for (j=0;j<M;++j)
        {
            scanf("%d",&t);
            row[i]+=find[t];
            col[j]+=find[t];
        }
    ans=row[0];
    for (i=1;i<N;++i)
        if (row[i]<ans) ans=row[i];
    for (j=0;j<M;++j)
        if (col[j]<ans) ans=col[j];
    printf("%d",ans);
    return 0;
}