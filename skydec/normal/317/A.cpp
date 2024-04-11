#include<stdio.h>
using namespace std;
typedef long long LL;
LL x,y,m;
bool pref(LL x,LL y)
{
     return ((x>=m)||(y>=m));
}
int main()
{
    scanf("%I64d%I64d%I64d",&x,&y,&m);
    if(pref(x,y))
    {
                 printf("0\n");
                 return 0;
                 }
    if(x<=0&&y<=0)
    {
                  printf("-1\n");
                  return 0;
                  }
    if(x>y){LL p=x;x=y;y=p;}
    LL step=(-x)/y;
    if((-x)%y!=0)step++;
    x=step*y+x;
    while(1)
    {
            if(pref(x,y))
            {
                         printf("%I64d\n",step);
                         break;
                         }
            if(x<y)x+=y;else y+=x;
            step++;
            }
    return 0;
}