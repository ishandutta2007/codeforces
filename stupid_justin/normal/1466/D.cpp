#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=3e5+5;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
 
int n,id,l,r;
int a[N];
int ans;
vector<int> vec[N];
struct Node
{
	int w,deg;
}s[N];
bool cmp(Node x,Node y){return x.w<y.w;}
int deg[N],w[N];
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		ans=0;
		rd(n);for (int i=1;i<=n;i++) rd(s[i].w);
		for (int i=1;i<=n;i++) s[i].deg=0;
		for (int i=1;i<n;i++)
		{
			int x,y;rd(x);rd(y);
			s[x].deg++;s[y].deg++;
		}
		sort(s+1,s+n+1,cmp);
		for (int i=1;i<=n;i++) ans+=s[i].w;
		cout<<ans<<" ";
		int id=n;
		for (int i=1;i<=n-2;i++)
		{
			while (s[id].deg<=1) id--;
			ans+=s[id].w;
			s[id].deg--;
			cout<<ans<<" ";
		}
		cout<<endl;
		
	}
}