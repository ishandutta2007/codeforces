#include<bits/stdc++.h>
#define maxn 200005

using namespace std;
typedef long long ll;

ll pre[maxn],h[maxn],c[maxn],ans,n,x,y;
bool f[maxn];

void sub_union(int s,int t)
{
    if (h[s]<h[t]) swap(s,t);
    if (h[s]==h[t]) h[s]++;
    pre[t]=s; c[s]=min(c[s],c[t]);
}

int ffind(int s)
{
    if (pre[s]==s) return s;
    int tmp=ffind(pre[s]);
    pre[s]=tmp;
    return tmp;
}

int main()
{
    scanf("%d",&n);int m;scanf("%d",&m);
    for (int i=1;i<=n;i++)
    {
        pre[i]=i;h[i]=1;scanf("%d",&c[i]);
    }
    while (m--)
    {
        int u,v;scanf("%d%d",&x,&y);
        u=ffind(x);v=ffind(y);
        sub_union(u,v);
    }
    memset(f,false,sizeof(f));
    for (int i=1;i<=n;i++)
    {
        x=ffind(i);f[x]=true;
    }
    ans=0;
    for (int i=1;i<=n;i++) if (f[i]) ans+=c[i];
    printf("%lld\n",ans);return 0;
}