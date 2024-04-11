#include<map>
#include<cstdio>
#include<algorithm>

#define N 2010

using namespace std;

map<long long,unsigned int>Ans[N];
int a,b,c,prime[N],vis[N];

unsigned int dfs(int a,int b,int c,int now)
{
    if(a>b)swap(a,b);
    if(b>c)swap(b,c);
    if(a>b)swap(a,b);
    if(c==1)return 1;
    if(!now)return 1;
    long long hash=1ll*a*2001*2001+1ll*b*2001+c;
    if(Ans[now].find(hash)!=Ans[now].end())return Ans[now][hash];
    unsigned int nowans=0;
    for(int i=a,cnt1=0;i;i/=prime[now],cnt1++)
        for(int j=b,cnt2=0;j;j/=prime[now],cnt2++)
            for(int k=c,cnt3=0;k;k/=prime[now],cnt3++)
                nowans+=dfs(i,j,k,now-1)*(cnt1+cnt2+cnt3+1);
    return Ans[now][hash]=nowans;
}

int main()
{
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)swap(a,b);
    if(b>c)swap(b,c);
    if(a>b)swap(a,b);
    for(int i=2;i<=c;i++)
        if(!vis[i])
        {
            vis[i]=1;
            prime[++prime[0]]=i;
            for(int j=i+i;j<=c;j+=i)
                vis[j]=1;
        }
    printf("%u",dfs(a,b,c,prime[0])&((1<<30)-1));
}