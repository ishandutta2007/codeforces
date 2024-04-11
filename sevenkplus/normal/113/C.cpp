#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int l,r,S=0,l0,r0;
int p[20000],L=0;
bool A[10000010];
bool pr(int n)
{
    for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
    return 1;
}
void ff(int l0,int r0,int c)
{
    memset(A,1,sizeof A);
    for(int i=0;i<L;i++)
        if(p[i]*p[i]>r0*30+c)break;else
        {
            int k=p[i]*p[i];
            while(k%30!=c)k+=p[i];
            for(;k<=r0*30+c;k+=p[i]*30)A[k/30]=0;
        }
    for(int i=l0;i<=r0;i++)if(A[i])
    {
        int x=i*30+c;
        if(x==1)continue;
        if(l<=x&&x<=r&&x%4==1)S++;
    }
}
int main()
{
    for(int i=7;i<20000;i++)if(pr(i))p[L++]=i;
    scanf("%d%d",&l,&r);
    if(l<=2&&2<=r)S++;
    if(l<=5&&5<=r)S++;
    l0=l/30,r0=r/30;
    ff(l0,r0,1),ff(l0,r0,7),ff(l0,r0,11),ff(l0,r0,13),
    ff(l0,r0,17),ff(l0,r0,19),ff(l0,r0,23),ff(l0,r0,29);
/*
    A[0]=1;
    for(int i=0;i<100000000;i++)if(!A[i])
    {
        int p;
        if(i&1)p=i*3+2;else p=i*3+1;
        if(p*p>300000000)break;
        for(int j=p*p;j<300000000;j+=p*2)
            if(j%3==0)continue;else A[j/3]=1;
    }
    for(int i=0;i<100000000;i++)if(!A[i])
    {
        int p;
        if(i&1)p=i*3+2;else p=i*3+1;
        if(p%4==1&&l<=p&&p<=r)S++;
    }
*/
    printf("%d\n",S);
    return 0;
}