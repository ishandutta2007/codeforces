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
int n,m,q,ans,a[1010][1010],f[1010][1010][2];
signed main()
{
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			a[i][l]=1;
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
		{
			f[i][l][0]=f[i][l][1]=1;
			f[i][l][0]+=f[i][l-1][1];
			f[i][l][1]+=f[i-1][l][0];
			ans+=f[i][l][0]+f[i][l][1]-1;
		}
//	cout<<ans<<endl;
	while(q--)
	{
		int x=read(),y=read();
		int nx=x,ny=y,L=0,R=0;
		while(1)
		{
			if(L&1)
			{
				ny--;
				if(!a[nx][ny])
					break;
				L++;
			}
			else
			{
				nx--;
				if(!a[nx][ny])
					break;
				L++;
			}
		}
		nx=x,ny=y;
		while(1)
		{
			if(R&1)
			{
				nx++;
				if(!a[nx][ny])
					break;
				R++;
			}
			else
			{
				ny++;
				if(!a[nx][ny])
					break;
				R++;
			}
		}
//		cout<<"L:"<<L<<" "<<R<<endl;
		int sum=(L+1)*(R+1);
		nx=x,ny=y,L=0,R=0;
		while(1)
		{
			if(L%2==0)
			{
				ny--;
				if(!a[nx][ny])
					break;
				L++;
			}
			else
			{
				nx--;
				if(!a[nx][ny])
					break;
				L++;
			}
		}
		nx=x,ny=y;
		while(1)
		{
			if(R%2==0)
			{
				nx++;
				if(!a[nx][ny])
					break;
				R++;
			}
			else
			{
				ny++;
				if(!a[nx][ny])
					break;
				R++;
			}
		}
		int sum1=(R+1)*(L+1);
//		cout<<sum<<" "<<sum1<<endl;
		a[x][y]=1-a[x][y];
		if(a[x][y])
			ans+=(sum1+sum-1);
		else
			ans-=(sum1+sum-1);
		cout<<ans<<endl;
	}
	return 0;
}