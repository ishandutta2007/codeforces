#include<stdio.h>
#define MAXN 99999
using namespace std;
int tt[8];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            int u;scanf("%d",&u);tt[u]++;
            if(u==7||u==5)
            {
                          printf("-1\n");
                          return 0;
                          }
            }
    if(tt[1]!=n/3)
    {
                  printf("-1\n");
                  return 0;
                  }
    if(tt[2]+tt[3]!=tt[4]+tt[6]){printf("-1\n");return 0;}
    if(tt[3]>tt[6]){printf("-1\n");return 0;}
    for(int i=1;i<=tt[2];i++)
    {
            if(tt[4])
            {
                     tt[4]--;
                     printf("1 2 4\n");
                     }
            else
            if(tt[6])
            {
                     tt[6]--;
                     printf("1 2 6\n");
                     }
                     }
    for(int i=1;i<=tt[3];i++)printf("1 3 6\n");
    return 0;
}