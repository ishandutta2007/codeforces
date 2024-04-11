#include<stdio.h>
using namespace std;
int ans=0;
int n,q;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
            int u;scanf("%d",&u);
            if(i==j)ans^=u;
            }
    scanf("%d",&q);
    while(q--)
    {
              int opt;scanf("%d",&opt);
              if(opt==3)
              {
                        printf("%d",ans);
                        }
              else
              {
                  int p;scanf("%d",&p);
                  ans^=1;
                  }
                  }
    return 0;
}