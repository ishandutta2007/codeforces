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
int n,m,q,ans,sum,tot,lst,a[101],b[100001],c[100001],t[2][100001];
#define lowbit(x) (x&(-x))
void modify(int x,int y)
{
	for(int z=x*y;x<=m;x+=lowbit(x))
	{
		t[0][x]+=y;
		t[1][x]+=z;
	}
}
int query(int x)
{
	int an1=0,an2=0;
	for(int i=x;i;i^=lowbit(i))
	{
		an1+=t[0][i];
		an2+=t[1][i];
	}
	return an1*(x+1)-an2;
}
int find(int x)
{
	int res=0,i=1<<18;
	for(;i;i>>=1)
		if(res+i<m&&t[0][res+i]<x)
			x-=t[0][res+=i];
	return res;
}
signed main()
{
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=m;i++)
		b[i]=read();
	for(int i=1;i<=m;i++)
		sum+=b[i];
	for(int i=2;i<=m;i++)
		c[i-1]=b[i]-b[i-1];
	for(int i=1;i<m;i++)
		modify(i,c[i]-c[i-1]);
	while(q--)
	{
		int opt=read(),k=read(),d=read();
		if(opt==1)
			for(int i=n-k+1,j=0;i<=n;i++)
			{
				j+=d;
				a[i]+=j;
			}
		else
		{
			if(k==m)
			{
				modify(1,d);
				b[1]+=d;
			}
			else
				modify(m-k,d);
			sum+=k*(k+1)/2*d;
		}
		ans=0;
		lst=1;
		for(int i=1;i<n;i++)
		{
			int x=min(m,find(a[i+1]-a[i])+1);
			ans+=a[i]*(x-lst+1);
			ans+=query(x-1)+b[1];
			lst=x;
		}
		ans+=a[n]*(m-lst+1);
		cout<<ans+sum<<endl;
	}
	return 0;
}