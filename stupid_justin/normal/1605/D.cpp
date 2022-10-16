#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
#define wt(x) write(x)
using namespace std;
const int N=2e6+5;
const int mod=1e9+7;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if (x<0){putchar('-');x=-x;}if (x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,ans;
vector<int> T[N];
int dep[N];
int a[N];
vector<int> v[2],V[2];
bool vis[N];
void dfs(int u,int fa){dep[u]=dep[fa]+1;for (int v:T[u]) if (v!=fa) dfs(v,u);}
void DOIT()
{
	rd(n);for (int i=1;i<=n;i++) T[i].clear(),vis[i]=0;
	for (int i=1,x,y;i<n;i++) rd(x),rd(y),T[x].push_back(y),T[y].push_back(x);
	dfs(1,0);
	v[0].clear();v[1].clear();V[0].clear();V[1].clear();
	for (int i=1;i<=n;i++) v[dep[i]%2].push_back(i);
	if (v[0].size()>v[1].size()) swap(v[0],v[1]);
	int t=0;
	for (int i=0;i<=30;i++)
		if (v[0].size()>>i&1) 
			for (int j=0;j<(1<<i);j++) V[0].push_back((1<<i)+j),vis[(1<<i)+j]=1;
	for (int i=1;i<=n;i++) if (!vis[i]) V[1].push_back(i);
	//for (int x:V[0]) cout<<x<<" ";cout<<"\n";
	//for (int x:V[1]) cout<<x<<" ";cout<<"\n";
	for (int i=0;i<v[0].size();i++) a[v[0][i]]=V[0][i];
	for (int i=0;i<v[1].size();i++) a[v[1][i]]=V[1][i];
	for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<"\n";
}
signed main()
{
	int JYZ;rd(JYZ);while (JYZ--) DOIT();
}
//