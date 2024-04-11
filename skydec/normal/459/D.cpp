#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<map>
#define MAXN 1010000
using namespace std;
int n;
int data[MAXN];
int f[2][MAXN];
int cnt[MAXN];
int tmp[MAXN];
map<int,int>ls;
int ask(int v)
{
    int ans=0;for(;v;v-=v&-v)ans+=cnt[v];
    return ans;
}
void add(int v)
{
     for(;v<=1000000;v+=v&-v)cnt[v]++;
}
void read(int &x)
{
     char p=getchar();x=0;
     while(!(p<='9'&&p>='0'))p=getchar();
     while(p<='9'&&p>='0')x*=10,x+=p-48,p=getchar();
}
void init()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++)read(data[i]),tmp[i]=data[i];
     sort(tmp+1,tmp+1+n);
     int tot=0;
     for(int i=1;i<=n;i++)
     if(i==1||tmp[i]!=tmp[i-1])ls[tmp[i]]=++tot;
     for(int i=1;i<=n;i++)data[i]=ls[data[i]];
     memset(tmp,0,sizeof tmp);
     for(int i=1;i<=n;i++)
     {
             tmp[data[i]]++;
             f[0][i]=tmp[data[i]];
             }
     memset(tmp,0,sizeof tmp);
     for(int i=n;i>=1;i--)
     {
             tmp[data[i]]++;
             f[1][i]=tmp[data[i]];
             }
}
int main()
{
    init();
    long long ans=0;
    for(int i=n;i>=1;i--)
    {
            int d=ask(f[0][i]-1);
            ans=ans+1ll*d;
            add(f[1][i]);
            }
    printf("%I64d\n",ans);
    return 0;
}