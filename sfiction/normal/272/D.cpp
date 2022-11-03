/*
ID: Sfiction
OJ: CF
PROB: 272D
*/
#include <cstdio>
#include <cstdlib>
const int MAXN=100000;
int a[MAXN<<1];
int Comp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    long long M,ans;
    int N,i,j,k;
    int same;
    scanf("%d",&N);
    same=0;
    for (i=0;i<N;++i) scanf("%d",&a[i]);
    for (i=0;i<N;++i)
    {
        scanf("%d",&a[N+i]);
        if (a[N+i]==a[i]) ++same;
    }
    N<<=1;
    ans=1;
    scanf("%I64d",&M);
    qsort(a,N,sizeof(int),Comp);
    for (i=0;i<N;i=j)
    {
        for (j=i+1;j<N&&a[i]==a[j];++j);
        for (k=j-i;k;--k)
        {
            ans*=k;
            for (;same&&ans%2==0;--same) ans>>=1;
            ans%=M;
        }
    }
    printf("%I64d",ans);
    return 0;
}