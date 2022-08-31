#include<stdio.h>
using namespace std;
typedef long long LL;
LL f[41][41][2];
LL n,t;
bool sw[41];
int main()
{
    scanf("%I64d%I64d",&n,&t);n++;
    if(!t)
    {
          printf("0\n");
          return 0;
          }
    long reu=0;
    while(t!=1)
    {
               if(t%2!=0)
               {
                         printf("0\n");
                         return 0;
                         }
               t/=2;
               reu++;
               }
    t=reu;t++;
    if(t>40)
    {
            printf("0\n");
            return 0;
            }
    LL tmp=n;
    for(long i=40;i>=1;i--)
    {
             sw[i]=(tmp%2);
             tmp/=2;
             }
    f[0][0][1]=1;
    for(long i=0;i<=39;i++)
    for(long j=0;j<=i;j++)
    {
             f[i+1][j+sw[i+1]][1]+=f[i][j][1];
             f[i+1][j+1][0]+=f[i][j][0];
             if(sw[i+1])
             {
                        f[i+1][j][0]+=f[i][j][1];
                        }
             f[i+1][j][0]+=f[i][j][0];
             }
    printf("%I64d\n",f[40][t][0]+f[40][t][1]-(t==1));
    return 0;
}