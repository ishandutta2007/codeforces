/*
ID: Sfiction
OJ: CF
PROB: 274A
*/
/*
a*k^b(a,k)ab
bk=21 2 4 16 32
{1,2,4}{16,32}
Sceil(s/2)
a[maxk]O(K)k
a,bO(NlogN)
k=1
*/
#include <cstdio>
#include <cstdlib>
const int MAXN=100000;
int a[MAXN][2];
int Comp(const void *a,const void *b)
{
    if (*(int *)a==*(int *)b) return *(int *)(a+1)-*(int *)(b+1);
    return *(int *)a-*(int *)b;
}
int main()
{
    int k;
    int i,j,N;
    int sum;
    scanf("%d%d",&N,&k);
    for (i=0;i<N;++i)
    {
        scanf("%d",&a[i][0]);
        if (k!=1)
            for (a[i][1]=0;a[i][0]%k==0;++a[i][1]) a[i][0]/=k;
        else a[i][1]=1;
    }
    qsort(a,N,sizeof(int)*2,Comp);
    sum=0;
    for (i=0;i<N;i=j)
    {
        for (j=i+1;j<N&&a[i][0]==a[j][0];++j)
            if (k!=1&&a[j][1]!=a[j-1][1]+1) break;
        if (k!=1) sum+=(j-i+1)/2;
        else ++sum;
    }
    printf("%d",sum);
    return 0;
}