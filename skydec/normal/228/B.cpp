#include<stdio.h>
using namespace std;
long mapa[51][51];
long mapb[51][51];
long na,ma,nb,mb;
long x,y;long ansx,ansy;
char getnext()
{
    char p=getchar();
    while(!(p<='1'&&p>='0'))p=getchar();
    return p;
}
int main()
{
    scanf("%ld%ld",&na,&ma);
    for(long i=1;i<=na;i++)
    for(long j=1;j<=ma;j++)
    mapa[i][j]=getnext()-'0';
    scanf("%ld%ld",&nb,&mb);
    for(long i=1;i<=nb;i++)
    for(long j=1;j<=mb;j++)
    mapb[i][j]=getnext()-'0';
    long ans=0;
    for(x=-50;x<=50;x++)
    for(y=-50;y<=50;y++)
    {
        long reu=0;
        for(long i=1;i<=na;i++)
        for(long j=1;j<=ma;j++)
        if(i+x>=1&&i+x<=nb&&j+y>=1&&j+y<=mb)
        reu+=mapa[i][j]*mapb[i+x][j+y];
        if(reu>=ans)
        {
            ans=reu;ansx=x;ansy=y;
        }
    }
    printf("%ld %ld\n",ansx,ansy);
    return 0;
}