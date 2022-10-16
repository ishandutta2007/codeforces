#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
const int mod=998244353;
int n,m,k,ans;
struct node{
	int a[201][201];
	void init()
	{
		memset(a,0,sizeof(a));
	}
	void init1()
	{
		init();
		for(int i=1;i<=200;i++)
			a[i][i]=1;
	}
	node operator*(const node &x)
	{
		node res;
		res.init();
		for(int i=1;i<=200;i++)
			for(int l=1;l<=200;l++)
				for(int j=1;j<=200;j++)
					(res.a[i][l]+=a[i][j]*x.a[j][l]%mod)%=mod;
		return res;
	}
}A,I,D,bse,S;
node operator^(node x,int y)
{
	node res;
	res.init1();
	while(y)
	{
		if(y&1)
			res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
signed main()
{
	n=read();
	m=read();
	k=read();
	A.init();
	D.init();
	I.init1();
	bse.init();
	S.init();
	while(m--)
	{
		int x=read(),y=read();
		D.a[x][x]++;
		D.a[y][y]++;
		A.a[x][y]=A.a[y][x]=1;
	}
	// for(int i=1;i<=n;i++)
	// {
		// for(int l=1;l<=n;l++)
			// cout<<A.a[i][l]<<" ";
		// cout<<endl;
	// }
	if(k==1)
	{
		for(int i=1;i<=n;i++)
			(ans+=A.a[i][i])%=mod;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			S.a[i+n][l]=A.a[i][l];
	node AA=A^2;
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			S.a[i][l]=(AA.a[i][l]-D.a[i][l]+mod)%mod;
	k-=2;
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			bse.a[i][l]=A.a[i][l];
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			bse.a[i][l+n]=(I.a[i][l]-D.a[i][l]+mod)%mod;
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			bse.a[i+n][l]=I.a[i][l];
	S=(bse^k)*S;
	for(int i=1;i<=n;i++)
		(ans+=S.a[i][i])%=mod;
	cout<<ans;
	return 0;
}