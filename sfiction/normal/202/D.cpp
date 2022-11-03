/*
ID: Sfiction
OJ: CF
PROB: 202D
*/
#include <cstdio>
long long row[1000],col[1000];
void calc(int &ans,long long &s,int &n,long long (&a)[1000])
{
    int i,j;
    long long t,t1;
    s=-1;
    for (i=0;i<n;++i)
    {
        t=0;
        for (j=0;j<i;++j)
        {
            t1=((i-j)<<1)-1;
            t+=t1*t1*a[j];
        }
        for (;j<n;++j)
        {
            t1=((j-i)<<1)+1;
            t+=t1*t1*a[j];
        }
        if (s==-1||s>t)
        {
            s=t;
            ans=i;
        }
    }
}
int main()
{
    int n,m;
    int i,j;
    int li,lj;
    long long t,si,sj;
    scanf("%d%d",&n,&m);
    for (i=0;i<n;++i)
        for (j=0;j<m;++j)
        {
            scanf("%I64d",&t);
            row[i]+=t;
            col[j]+=t;
        }
    calc(li,si,n,row);
    calc(lj,sj,m,col);
    printf("%I64d\n%d %d",(si+sj)<<2,li,lj);
    return 0;
}