#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
//const int INF=4e18;
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
int n,k,tot,ans,f[300001],ch[2][300001*32],id[300001*32],pre[300001];
array<int,2> a[300001];
void insert(int x,int y)
{
	int cnt=0;
	for(int i=31;~i;i--)
	{
		int c1=(x>>i&1);
		if(!ch[c1][cnt])
			ch[c1][cnt]=++tot;
		cnt=ch[c1][cnt];
		if(f[y]>f[id[cnt]])
			id[cnt]=y;
	}
}
int query(int x)
{
	int res=0,cnt=0;
	for(int i=31;~i;i--)
	{
		int c1=(x>>i&1),c2=(k>>i&1);
		if(!c2)
		{
			int y=ch[c1^1][cnt];
			if(f[res]<f[id[y]])
				res=id[y];
		}	
		cnt=ch[c1^c2][cnt];
		if(!cnt)
			break;
	}
	if(f[res]<f[id[cnt]])
		res=id[cnt];
	return res;
}
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		a[i]={read(),i};
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		int x=query(a[i][0]);
		f[i]=max(f[i],f[x]+1);
		if(f[i]>f[ans])
			ans=i;
		pre[i]=x;
		insert(a[i][0],i);
	}
	if(f[ans]==1)
	{
		puts("-1");
		return 0;
	}
	cout<<f[ans]<<endl;
	while(ans)
	{
		cout<<a[ans][1]<<" ";
		ans=pre[ans];
	}
	return 0;
}