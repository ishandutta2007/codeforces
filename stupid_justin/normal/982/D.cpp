#include<bits/stdc++.h>
#define int long long
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
const int maxn=5e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,ans;

int FA[N],sz[N],vis[N];
void init(int n){for (int i=1;i<=n;i++) FA[i]=i,sz[i]=1;}
int getfa(int x){if (FA[x]==x)return x;return FA[x]=getfa(FA[x]);}
void merge(int u,int v){u=getfa(u);v=getfa(v);if (u!=v) FA[u]=v,sz[v]+=sz[u],sz[u]=0;}
int tot=0,cnt=0,L=1,Max=0;
struct Node{int x,p;}a[N];
bool cmp(Node a,Node b){return a.x<b.x;}
signed main()
{
	rd(n);for (int i=1;i<=n;i++){a[i].p=i;rd(a[i].x);}
    sort(a+1,a+n+1,cmp);init(n);
	for (int i=1;i<=n;i++)
	{
        int p=a[i].p;
		vis[p]=1;
		if (!vis[p-1] && !vis[p+1]){tot++;if (L==1) cnt++;}
		else
		{
			if (vis[p-1]) merge(p-1,p);
			if (vis[p+1]) merge(p+1,p);
            if (vis[p-1] && vis[p+1]) tot--;
			if (sz[p]>L) L=sz[p],cnt=1; 
			else if (sz[p]==L) cnt++;
		}
		if (tot==cnt && tot>Max) Max=tot,ans=a[i].x+1;
	}
    cout<<ans<<endl;
}