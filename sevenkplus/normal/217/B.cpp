#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 1000000007
int n,m,S,T,U=INF,Ui;
void ff(int x,int y)
{
    if(x==1)
    {
        S+=y-2,T+=y-1;
        return;
    }else
    if(y==1)
    {
        S+=x-1,T+=x-1;
        return;
    }
    if(x>y)S+=x/y-1,T+=x/y,ff(x%y,y);
    if(y>x)S+=y/x-1,T+=y/x,ff(x,y%x);
}
void gg(int x,int y)
{
    if(x==1)
    {
        S+=y-2,T+=y-1;
        for(int i=0;i<y-1;i++)putchar('B');
        return;
    }else
    if(y==1)
    {
        S+=x-1,T+=x-1;
        for(int i=0;i<x-1;i++)putchar('T');
        return;
    }
    if(x>y)
    {
        S+=x/y-1,T+=x/y,gg(x%y,y);
        for(int i=0;i<x/y;i++)putchar('T');
    }
    if(y>x)
    {
        S+=y/x-1,T+=y/x,gg(x,y%x);
        for(int i=0;i<y/x;i++)putchar('B');
    }
}
int main()
{
    scanf("%d%d",&n,&m);--n;
    if(n==0&&m==1){printf("0\nT\n");return 0;}
    for(int i=1;i<=m;i++)if(__gcd(i,m)==1)
    {
        S=0,T=0,ff(i,m);
        if(T==n&&S<U)U=S,Ui=i;
        S=0,T=0,ff(m,i);
        if(T==n&&S<U)U=S,Ui=-i;
    }
    if(U==INF)puts("IMPOSSIBLE");else
    {
        printf("%d\n",U);
        putchar('T');
        if(Ui>0)gg(abs(Ui),m);
        else gg(m,abs(Ui));
        puts("");
    }
    return 0;
}