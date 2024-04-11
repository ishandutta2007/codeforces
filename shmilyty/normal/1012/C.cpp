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
int n,a[5001],f[2501][3]; 
//0: 1: 2: 
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	memset(f,0x3f3f3f,sizeof(f));
	f[0][0]=0;
	f[1][1]=0; 
	for(int i=2;i<=n;i++)
		for(int l=(i+1)/2;l;l--)
		{
			f[l][0]=min(f[l][0],f[l][2]);
			f[l][2]=f[l][1]+max(0ll,a[i]-a[i-1]+1);
			f[l][1]=min(f[l-1][0]+max(0ll,a[i-1]-a[i]+1),f[l-1][2]+max(0ll,min(a[i-2]-1,a[i-1])-a[i]+1));
		}
	for(int i=1;i<=(n+1)/2;i++)
		cout<<min({f[i][0],f[i][1],f[i][2]})<<" ";
	return 0;
}