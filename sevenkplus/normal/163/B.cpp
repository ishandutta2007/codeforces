#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 100010
int n,m,h,a[N],b[N],p[N];long double B[N];
bool cmp(int x,int y){return a[x]<a[y]||a[x]==a[y]&&b[x]<b[y];}
bool can(long double x)
{
    int v=0;
    for(int i=0;i<n;i++)if((v+1)*B[i]<x)v++;
    return v>=m;
}
int main()
{
    scanf("%d%d%d",&n,&m,&h);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    for(int i=0;i<n;i++)scanf("%d",b+i);
    for(int i=0;i<n;i++)p[i]=i;
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++)B[i]=(long double)1.0/b[p[i]];
    long double le=0,ri=1e15+2;
    for(int _=200;_--;)
    {
        long double M=(le+ri)/2;
        if(can(M))ri=M;else le=M;
    }
    for(int i=0,v=0;i<n&&v<m;i++)
        if((v+1)*B[i]<ri)printf("%d%c",p[i]+1,v==m-1?'\n':' '),v++;
    return 0;
}