#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=2e5+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int n;
map<pair<int,int>,int>Map;
int fa[N],num[N],x[N],y[N];
int getfa(int x){if (fa[x]==x) return x;return fa[x]=getfa(fa[x]);}
bool R(int i,int j,int k){return (x[i]==x[j] && abs(y[i]-y[j])<=k)||(y[i]==y[j]&&abs(x[i]-x[j])<=k);}
bool chk(int k)
{
	Map.clear();int tot=n,cnt=0;for (int i=1;i<=n;i++) fa[i]=i,num[i]=0;
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) if (getfa(i)!=getfa(j)) if (R(i,j,k)) fa[getfa(i)]=getfa(j),tot--;
	if (tot==1) return 1;if (tot>4) return 0;
	if (tot==2) {for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) if (getfa(i)!=getfa(j)) if (R(i,j,k+k)) return 1;}
	for (int i=1;i<=n;i++){int u=getfa(i);if (!num[u]) num[u]=(1<<cnt++);}
	for (int i=1,u=getfa(i);i<=n;i++,u=getfa(i)) for (int j=i+1,v=getfa(j);j<=n;j++,v=getfa(j)) if (u!=v) if (abs(x[i]-x[j])<=k && abs(y[i]-y[j])<=k)
	{
		Map[mp(x[i],y[j])]|=num[u]|num[v];Map[mp(x[j],y[i])]|=num[u]|num[v];
		if (Map[mp(x[i],y[j])]==((1<<cnt)-1)||(Map[mp(x[j],y[i])]==((1<<cnt)-1))) return 1;
	}
	return 0;
}
signed main()
{
	rd(n);for (int i=1;i<=n;i++) rd(x[i]),rd(y[i]);
	int l=1,r=2e9,ans=0;
	if (!chk(r)) {puts("-1");return 0;}
	while (l<=r){int mid=(l+r)>>1;if (chk(mid)) r=mid-1,ans=mid;else l=mid+1;}
    cout<<ans<<endl;
}