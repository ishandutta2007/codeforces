#include<stdio.h>
#include<cstdlib>
#include<map>
using namespace std;
long n;
long tot=0;
map<long,bool>ls;
void dfs(long long now,long x,long y)
{
     if(now>n)return;
     if(now)
     {
            if(!ls[now]){tot++;ls[now]=true;}
            }
     if(now*10ll+1ll*x!=0)
     dfs(now*10ll+1ll*x,x,y);
     if(now*10ll+1ll*y!=0)
     dfs(now*10ll+1ll*y,x,y);
}
int main()
{
    scanf("%ld",&n);
    for(long i=0;i<=9;i++)
    for(long j=i+1;j<=9;j++)
    dfs(0,i,j);
    printf("%ld\n",tot);
    return 0;
}