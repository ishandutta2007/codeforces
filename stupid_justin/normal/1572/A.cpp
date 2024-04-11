
#include<bits/stdc++.h>
#define rd(x) x=read()
#define wt(x) write(x)
using namespace std;
const int N=2e6+5;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int n,ans;
vector<int> G[N];
int f[N],d[N];
int Q[N],l,r;
void DOIT()
{
    rd(n);for (int i=1;i<=n;i++) d[i]=0,f[i]=-1,G[i].clear();
    for (int i=1,k,x;i<=n;i++)
    {
        rd(k);
        for (int j=1;j<=k;j++) rd(x),G[x].push_back(i),d[i]++;
    }
    l=r=0;
    for (int i=1;i<=n;i++) if (d[i]==0) Q[++r]=i,f[i]=1;
    while (l<r)
    {
        l++;int u=Q[l];
        for (int v:G[u]) if (d[v]>0) 
        {
            d[v]--;f[v]=max(f[v],f[u]+(u>v));
            if (d[v]==0) Q[++r]=v;
        }
    }
    ans=0;
    for (int i=1;i<=n;i++) ans=max(ans,f[i]);
    for (int i=1;i<=n;i++) if (d[i]>0) ans=-1;
    cout<<ans<<"\n";
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}
/*
*/