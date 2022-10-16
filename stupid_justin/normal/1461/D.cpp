#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=2e6+5;
const int M=5005;
const int mod=998244353;
const int inf=0x3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
 
int n,m;
int a[N],sum[N];
vector<int> del;
void get(int l,int r)
{
	if (l>r) return;
	del.push_back(sum[r]-sum[l-1]);
	if (a[l]==a[r]) return;
	int mid=(a[r]+a[l])/2;
	int p=upper_bound(a+l,a+r,mid)-a-1;
	if (p==n) return;
	if (p>=l) get(l,p);
	if (p<=r) get(p+1,r);
}
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		del.clear();
		rd(n);rd(m);
		for (int i=0;i<=n+2;i++) sum[i]=0;
		for (int i=1;i<=n;i++) rd(a[i]);
		a[n+1]=inf;
		sort(a+1,a+n+1);
		for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
		get(1,n);
		sort(del.begin(),del.end());
		
		while (m--)
		{
			int x;rd(x);
			vector<int>::iterator p=lower_bound(del.begin(),del.end(),x);
			if (p==del.end()) puts("No");else
			if (*p!=x) puts("No");
			else puts("Yes");
		}
	}
}