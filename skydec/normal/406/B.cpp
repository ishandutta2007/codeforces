#include<stdio.h>
#define MAXN 1100000
using namespace std;
bool use[MAXN];
int n;
int data[MAXN];
int S;
bool ans[MAXN];
int tmp[MAXN];
int main()
{
    scanf("%d",&n);S=1000000;
    for(int i=1;i<=n;i++)
    {
            scanf("%d",&data[i]);
            use[data[i]]=1;
            }
    for(int i=1;i<=n;i++)
    if(!ans[data[i]])
    if(!use[S-data[i]+1])
    {
                     ans[S-data[i]+1]=1;
                     }
    for(int i=1;i<=S/2;i++)
    if((!use[i])&&(!use[S+1-i]))tmp[++tmp[0]]=i;
    for(int i=1;i<=n;i++)
    if(use[data[i]]&&use[S-data[i]+1])
    {
                      ans[tmp[tmp[0]]]=1;
                      ans[S-tmp[tmp[0]]+1]=1;
                      tmp[0]--;
                      use[data[i]]=0;
                      }
    int u=0;
    for(int i=1;i<=S;i++)if(ans[i])u++;
    printf("%d\n",u);
    for(int i=1;i<=S;i++)
    if(ans[i])printf("%d ",i);
    return 0;
}