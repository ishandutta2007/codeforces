#include<stdio.h>
#define MAXN 5005
using namespace std;
int cnt[MAXN];
int data[MAXN];
int n,m;
struct opt
{
       int k,l,r,b;
}oo[MAXN];
int min(int x,int y){if(x<y)return x;return y;}
int jc[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)data[i]=1000000000;
    for(int j=1;j<=m;j++)
    {
            scanf("%d%d%d%d",&oo[j].k,&oo[j].l,&oo[j].r,&oo[j].b);
            if(oo[j].k==1)
            {
                      for(int i=oo[j].l;i<=oo[j].r;i++)cnt[i]+=oo[j].b;
            #define l oo[j].l
            #define r oo[j].r
                      }
            else
            {
                      for(int i=l;i<=r;i++)data[i]=min(data[i],oo[j].b-cnt[i]);
                                            }
                                            }
    for(int i=1;i<=n;i++)jc[i]=data[i];
    for(int j=1;j<=m;j++)
    {
            if(oo[j].k==1)
            {
                      for(int i=l;i<=r;i++)data[i]+=oo[j].b;
                      }
            else
            {
                int MAX=-1000000000;
                for(int i=l;i<=r;i++)
                if(data[i]>MAX)MAX=data[i];
                if(MAX!=oo[j].b)
                {
                                printf("NO\n");
                                return 0;
                                }
                                }
                                }
    printf("YES\n");
    for(int i=1;i<=n;i++)printf("%d ",jc[i]);
    return 0;
}