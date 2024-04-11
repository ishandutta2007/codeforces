#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=1e6+5;
const int M=6e5+5;
const int SZ=550;
const double eps=1e-9;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int vis[N],p[N],cnt;
void Init(int n)
{
    for (int i=2;i<=n;i++) 
    {
        if (!vis[i]) p[++cnt]=i,vis[i]=i;
        for (int j=1;j<=cnt && p[j]*i<=n;j++) 
        {
            vis[p[j]*i]=p[j];
            if (i%p[j]==0) break;
        }
    }
}
int n,q,m;
map<int,bool> Map[N];
int a[N],fa[N];
int getfa(int x){if (x==fa[x]) return x;return fa[x]=getfa(fa[x]);}
vector<int> v[N];
int tmp[N],CNT;
signed main()
{
    m=1e6+1;Init(m);
    rd(n);rd(q);for (int i=1;i<=n;i++) rd(a[i]);
    for (int i=1;i<=m;i++) fa[i]=i;
    for (int i=1;i<=n;i++)
    {
        int x=a[i];
        while (x!=1) v[vis[x]].push_back(a[i]),x/=vis[x];
    }
    for (int i=1;i<=m;i++) if (v[i].size()>1) for (int j=1;j<v[i].size();j++) 
    {
        int x=v[i][j-1],y=v[i][j];
        x=getfa(x),y=getfa(y);
        if (x!=y) fa[x]=y;
        //cout<<"("<<x<<","<<y<<")"<<endl;
    }
    for (int i=1;i<=n;i++)
    {
        int x=a[i]+1;
        CNT=0;
        while (x!=1) 
        {
            int y=vis[x];
            if (y!=tmp[CNT]) tmp[++CNT]=y;
            if (v[y].size()) Map[getfa(v[y][0])][getfa(a[i])]=Map[getfa(a[i])][getfa(v[y][0])]=1;
            x/=vis[x];
        }
        for (int i=1;i<CNT;i++) if (v[tmp[i]].size()) 
        for (int j=i+1;j<=CNT;j++) if (v[tmp[j]].size()) 
        Map[getfa(v[tmp[i]][0])][getfa(v[tmp[j]][0])]=Map[getfa(v[tmp[j]][0])][getfa(v[tmp[i]][0])]=1;
    }
    while (q--)
    {
        int s,t;
        rd(s);rd(t);s=a[s],t=a[t];
        s=getfa(s),t=getfa(t);
        if (s==t) puts("0");else 
        if (Map[s][t]) puts("1");else 
        puts("2");
    }
    

    
}
/*

*/