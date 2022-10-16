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
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 

int C(int n,int m){if (m>n || m<0) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
int f(int n,int m){n--;m--;return C(n+m,n);}
int n,ans,idn,id1;
bool flagn,flag1;
int a[N];
int mn[N],mx[N];
void ask(int t,int i,int j,int x)
{
	printf("? %lld %lld %lld %lld",t,i,j,x);
	cout<<endl;
	cin>>ans;
}
void getn(int i,int j)
{
	ask(1,i,j,n-1);
	mx[i]=ans;
	if (ans==n) {idn=j;flagn=1;}
	if (ans==n-1)
	{
		ask(1,j,i,n-1);
		if (ans==n) {idn=i;flagn=1;}
	}
}
void get1(int i,int j)
{
	ask(2,i,j,1);
	mn[i]=ans;
	if (ans==1) {id1=i;flag1=1;}
	if (ans==2)
	{
		ask(2,j,i,1);
		if (ans==1) {id1=j;flag1=1;}
	}
}
void getans(int i,int j)
{
	if (i==id1)
	{
		a[i]=1;
		ask(1,i,j,n-1);
		a[j]=ans;
		return;
	}
	if (i==idn)
	{
		a[i]=n;
		ask(2,j,i,1);
		a[j]=ans;
		return;
	}
	if (j==id1)
	{
		a[j]=1;
		ask(1,j,i,n-1);
		a[i]=ans;
		return;
	}
	if (j==idn)
	{
		a[j]=n;
		ask(2,i,j,1);
		a[i]=ans;
		return;
	}
	ask(1,i,j,mn[i]);
	if (ans==mn[i]) a[i]=mx[i],a[j]=mn[i];
	else a[i]=mn[i],a[j]=mx[i];
}
void solve()
{
	rd(n);idn=id1=0;flag1=flagn=0;
	for (int i=1;i<n;i+=2) getn(i,i+1);
	getn(n,1);
	for (int i=1;i<n;i+=2) get1(i,i+1);
	get1(n,1);
	for (int i=1;i<n;i+=2)
	{
		getans(i,i+1);
	}
	getans(n,1);
	cout<<"! ";
	for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;

}
signed main()
{
	int T;cin>>T;
	while (T--)
	{
		solve();
	}
}