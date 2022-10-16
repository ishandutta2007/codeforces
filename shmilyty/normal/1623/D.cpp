#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
const int mod=1e9+7;
int qp(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)
			(res*=x)%=mod;
		(x*=x)%=mod;
		y>>=1;
	}
	return res;
}
int t,n,m,x,y,x1,y1,xx,yy,p,inv,top,t1,t2,tt1,tt2,stk[200001];
int frac(int x)
{
	return (x*inv)%mod;
}
void solve()
{
	n=read();
	m=read();
	x=read();
	y=read();
	x1=x;
	y1=y;
	xx=read();
	yy=read();
	p=read();
	top=0;
	t1=t2=1;
	if(x+t1==n+1||x+t1==0)
		t1=-t1;
	if(y+t2==m+1||y+t2==0)
		t2=-t2;
	tt1=t1;
	tt2=t2;
//	cout<<tt1<<" "<<tt2<<endl;
	int ans=0;
	while(1)
	{
//		cout<<x<<" "<<y<<" "<<t1<<" "<<t2<<endl;
//		system("pause");
		if(x==xx||y==yy)
			stk[++top]=ans;
		x+=t1;
		y+=t2;
		ans++;
		if(x+t1==n+1||x+t1==0)
			t1=-t1;
		if(y+t2==m+1||y+t2==0)
			t2=-t2;
		if(x==x1&&y==y1&&t1==tt1&&t2==tt2)
			break;
	}
//	cout<<ans<<" "<<top<<endl;
	int up=0,down=1;
	for(int i=1;i<=top;i++)
	{
		int k=stk[i];
//		cout<<k<<endl;
		(up+=down*frac(p)%mod*k%mod)%=mod;
		(down*=frac(100-p))%=mod;
	}
	(up+=down*ans%mod)%=mod;
	down=(1+mod-down)%mod;
	cout<<(up*qp(down,mod-2))%mod<<'\n'; 
}
signed main()
{
	inv=qp(100,mod-2);
	t=read();
	while(t--)
		solve();
	return 0;
}