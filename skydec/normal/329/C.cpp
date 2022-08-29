#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<map>
#define MAXN 110000
using namespace std;
map<int,int>head[MAXN];
int n,m;
int f[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
            int a,b;scanf("%d%d",&a,&b);
            head[a][b]=head[b][a]=1;
            }
    for(int ss=1;ss<=1000;ss++)
    {
            for(int i=1;i<=n;i++)f[i]=i;
            random_shuffle(f+1,f+1+n);
            f[n+1]=f[1];
            bool fs=0;
            for(int i=1;i<=m;i++)
            if(head[f[i]][f[i+1]])fs=1;
            if(!fs)
            {
                  for(int i=1;i<=m;i++)
                  printf("%d %d\n",f[i],f[i+1]);
                  return 0;
                  }
                  }
    printf("-1\n");
    return 0;
}