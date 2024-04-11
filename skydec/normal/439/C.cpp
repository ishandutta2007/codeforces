#include<stdio.h>
#include<stdlib.h>
#define MAXN 110000
using namespace std;
long n,k,p;
long a[MAXN];
long tmpodd[MAXN],tmpeven[MAXN];
long tmp[MAXN][3];
long finalans[MAXN];
long odd=0,even=0;
int main()
{
    scanf("%ld%ld%ld",&n,&k,&p);
    for(long i=1;i<=n;i++)
    {
             scanf("%ld",&a[i]);
             if(a[i]&1)
             {
                       odd++;
                       tmpodd[++tmpodd[0]]=a[i];
                       }
             else
             {
                       even++;
                       tmpeven[++tmpeven[0]]=a[i];
                       }
             }
    for(long i=1;i<=k-1;i++)
    if(i<=p)
    {
            //printf("%ld %ld\n",even,odd);system("pause");
            if(even!=0)
            {
                       tmp[i][1]=tmpeven[tmpeven[0]--];
                       tmp[i][0]=1;
                       even--;
                       }
            else
            if(odd>=2)
            {
                      //printf("2 %ld %ld\n",tmpodd[tmpodd[0]],tmpodd[tmpodd[0]-1]);
                      tmp[i][0]=2;
                      tmp[i][1]=tmpodd[tmpodd[0]];
                      tmp[i][2]=tmpodd[tmpodd[0]-1];
                      tmpodd[0]-=2;
                      odd-=2;
                      }
            else
            {
                      printf("NO\n");
                      return 0;
                      }
                      }
    else
    {
                      //printf("%ld %ld\n",even,odd);system("pause");
                      if(odd==0)
                      {
                                printf("NO\n");
                                return 0;
                                }
                      tmp[i][0]=1;
                      tmp[i][1]=tmpodd[tmpodd[0]--];
                      odd--;
                      }
    //system("pause");
    //printf("%ld %ld\n",even,odd);
    if((odd==0)&&(even==0))
    {
                       printf("NO\n");
                       return 0;
                       }
    finalans[0]=odd+even;
    for(long i=1;i<=odd;i++)finalans[i]=tmpodd[i];
    for(long i=odd+1;i<=odd+even;i++)finalans[i]=tmpeven[i-odd];
    if(k==p)
    {
            if(odd&1)
            {
                        printf("NO\n");
                        return 0;
                        }
                        }
    else
    {
                        if(odd%2==0)
                        {
                                 printf("NO\n");
                                 return 0;
                                 }
                                 }
    printf("YES\n");
    for(long i=1;i<=k-1;i++)
    {
             printf("%ld ",tmp[i][0]);
             for(long j=1;j<=tmp[i][0];j++)printf("%ld ",tmp[i][j]);
             putchar('\n');
             }
    printf("%ld ",finalans[0]);
    for(long i=1;i<=finalans[0];i++)printf("%ld ",finalans[i]);
    return 0;
}