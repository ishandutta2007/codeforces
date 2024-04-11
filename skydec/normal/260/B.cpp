#include<stdio.h>
#include<cstring>
#define MAXN 110000
using namespace std;
char str[MAXN];
long len=0;
long cx[2016][14][33]={0};
bool big(long x)
{
     if(x==1||x==3||x==5||x==7||x==8||x==10||x==12)return true;
     return false;
}
long range(long x)
{
     if((x%4==0&&x%100!=0)||(x%400==0))return 29;
     return 28;
}
bool checknum(char s)
{
     return (s<='9'&&s>='0');
}
void check(long x)
{
     long y,m,d;
     if(str[x+2]!='-')return;
     if(str[x+5]!='-')return;
     for(long j=0;j<=9;j++)
     if(j!=2)
     if(j!=5)
     if(!checknum(str[x+j]))return;
     d=(str[x]-48)*10+(str[x+1]-48);
     m=(str[x+3]-48)*10+(str[x+4]-48);
     y=(str[x+6]-48)*1000+(str[x+7]-48)*100+(str[x+8]-48)*10+(str[x+9]-48);
     if(d<=0)return;
     if(m<=0)return;
     if(m>12)return;
     if(y<2013||y>2015)return;
     if(big(m)&&d>31)return;
     else
     if(!big(m)&&d>30)return;
     else if(m==2&&d>range(y))return;
     cx[y][m][d]++;
}
void pr(long limit,long x)
{
     if(x<limit)putchar('0');
     printf("%ld",x);
}
int main()
{
    scanf("%s",str+1);
    len=strlen(str+1);
    for(long i=1;i+10-1<=len;i++)check(i);
    long y,d,m;y=d=m=0;
    for(long i=2013;i<=2015;i++)
    for(long j=1;j<=12;j++)
    for(long k=1;k<=31;k++)
    if(cx[i][j][k]>cx[y][m][d])
    {
                               y=i;
                               m=j;
                               d=k;
                               }
    pr(10,d);
    printf("-");
    pr(10,m);
    printf("-");
    printf("%ld\n",y);
    return 0;
}