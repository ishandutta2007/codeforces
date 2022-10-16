#include<bits/stdc++.h>
#define int long long
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=105;
const int M=21;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n;
bool vis[N];
bool a[N][N];
int q[N];
set<int> S[N];
int tot;
bool edge(int u,int v){int o;cout<<1<<" "<<u<<" "<<v<<endl;cin>>o;return o;}
void merge(int x,int y){for (int u:S[y]) S[x].insert(u);S[y].clear();}
void init()
{
	memset(vis,0,sizeof(vis));
	memset(a,0,sizeof(a));
	memset(q,0,sizeof(q));
	for (int i=1;i<=tot;i++) S[i].clear();
	tot=0;
	cin>>n;
}
void solve()
{
	for (int i=0;i<n;i++)
	{
		int l=1,r=tot+1;
		while (l<r) {int mid=(l+r)/2;if (mid==tot+1 || edge(i,q[mid])) r=mid;else l=mid+1;}
		for (int i=tot;i>=l;i--) q[i+1]=q[i];q[l]=i;tot++;
	}
	for (int i=1;i<=tot;i++) S[i].insert(q[i]);
	int m=tot;
	while (m>1)
	{
		for (int u:S[m]) if (!vis[u])
		{
			cout<<2<<" "<<u<<" ";
			int cnt=0;
			for (int i=1;i<=m-1;i++) cnt+=S[i].size();
			cout<<cnt<<" ";
			for (int i=1;i<=m-1;i++) for (int v:S[i]) cout<<v<<" ";cout<<endl;
			int o;cin>>o;if (o) {merge(m-1,m);break;}
			vis[u]=1;
		}
		m--;
	}
	for (int i=1;i<=tot;i++) for (int j=i;j<=tot;j++) for (int u:S[i]) for (int v:S[j]) a[u][v]=1;
}
void print()
{
	cout<<3<<endl;
	for (int i=0;i<n;i++) {for (int j=0;j<n;j++) cout<<a[i][j];cout<<endl;}
	int o;cin>>o;
}
signed main()
{
	int T;cin>>T;while (T--){init();solve();print();}

}