#include<stdio.h>
#define MAXN 110000
using namespace std;
int n;
int next[MAXN];
bool die[MAXN]={false};
int data[MAXN];
int q[MAXN*10];
int times[MAXN]={0};
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            scanf("%d",&data[i]);
            next[i]=i+1;
            }
    next[n]=-1;
    for(int i=n-1;i>=1;i--)if(data[i]>data[i+1])q[++q[0]]=i;
    for(int i=1;i<=q[0];i++)
    {
            int x=q[i];
            if(die[x])continue;
            if(next[x]==-1)continue;
            if(data[x]<=data[next[x]])continue;
            times[x]++;
            die[next[x]]=1;
            next[x]=next[next[x]];
            q[++q[0]]=x;
            }
    int u=0;
    for(int i=1;i<=n;i++)if(u<times[i])u=times[i];
    printf("%d\n",u);
    return 0;
}