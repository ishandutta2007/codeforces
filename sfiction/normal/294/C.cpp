/*
ID: Sfiction
OJ: CF
PROB: 294C
*/
#include <cmath>
#include <cstdio>
#include <cstdlib>
const int MAXN=1000,MAXP=11;
const int pri[MAXP]={2,3,5,7,11,13,17,19,23,29,31};
const long long p=1000000007;
int on[MAXN+2];
int times[MAXP],other[MAXN+1];
int Comp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
void Mult(int v,int x)
{
    int i,j;
    for (i=0;x>1&&i<MAXP;++i)
    {
        for (j=0;x%pri[i]==0;++j) x/=pri[i];
        times[i]+=v*j;
    }
    if (x>1) other[x]+=v;
}
long long Qpow(long long x,int N)
{
    long long ret;
    for (ret=1;N>0;N>>=1)
    {
        if (N&1) ret=ret*x%p;
        x=x*x%p;
    }
    return ret;
}
long long Calc()
{
    long long i,sum=1;
    for (i=0;i<MAXP;++i) sum=sum*Qpow(pri[i],times[i])%p;
    for (i=0;i<=MAXN;++i)
        if (other[i]) sum=sum*Qpow(i,other[i])%p;
    return sum;
}
int main()
{
    int N,M;
    int i,j,sum;
    scanf("%d%d",&N,&M);
    for (i=N-M;i>1;--i) Mult(1,i);
    for (i=1;i<=M;++i) scanf("%d",&on[i]);
    on[M+1]=N+1;
    qsort(on+1,M,sizeof(int),Comp);
    for (i=0;i<=M;++i)
        for (j=on[i+1]-on[i]-1;j>1;--j) Mult(-1,j);
    for (sum=0,i=1;i<M;++i)
        if (on[i+1]-on[i]>2) sum+=on[i+1]-on[i]-2;
    printf("%I64d",Qpow(2,sum)*Calc()%p);
    return 0;
}