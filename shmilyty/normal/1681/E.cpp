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
struct node
{
	int a[2][2];
}bse[100001],t[400001];
node operator*(node x,node y)
{
	node res;
	memset(res.a,0x3f,sizeof(res.a));
	for(int i=0;i<2;i++)
		for(int l=0;l<2;l++)
			for(int j=0;j<2;j++)
				res.a[i][l]=min(res.a[i][l],x.a[i][j]+y.a[j][l]);
	return res;
}
int n,m;
array<int,2>cnt[100001][2];
void build(int x,int l,int r)
{
	if(l==r)
	{
		// cout<<x<<endl;
		t[x]=bse[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	t[x]=t[x<<1]*t[x<<1|1];
}
node query(int x,int l,int r,int L,int R)
{
	// cout<<L<<" "<<R<<endl;
	if(L<=l&&r<=R)
		return t[x];
	int mid=(l+r)>>1;
	if(L<=mid&&R>mid)
		return query(x<<1,l,mid,L,R)*query(x<<1|1,mid+1,r,L,R);
	if(L<=mid)
		return query(x<<1,l,mid,L,R);
	if(R>mid)
		return query(x<<1|1,mid+1,r,L,R);
}
signed main()
{
	n=read();
	for(int i=0;i<n-1;i++)
	{
		for(int l=0;l<2;l++)
			cnt[i][l]={read(),read()};
		if(i)
			for(int l=0;l<2;l++)
				for(int j=0;j<2;j++)
					bse[i].a[l][j]=abs(cnt[i][j][0]-cnt[i-1][l][0]-(l==0))+abs(cnt[i][j][1]-cnt[i-1][l][1]-(l==1))+1;
	}
	// for(int i=1;i<n-1;i++)
	// {
	// 	for(int l=0;l<2;l++)
	// 		for(int j=0;j<2;j++)
	// 			cout<<bse[i].a[l][j]<<" ";
	// 	cout<<endl;
	// }
	if(n>2)
		build(1,1,n-2);
	m=read();
	// for(int l=0;l<2;l++)
		// for(int j=0;j<2;j++)
			// cout<<k.a[l][j]<<endl;
	// cout<<endl;
	while(m--)
	{
		int x=read(),y=read(),xx=read(),yy=read();
		if(max(x,y)>max(xx,yy))
		{
			swap(x,xx);
			swap(y,yy);
		}
		if(max(x,y)==max(xx,yy))
		{
			cout<<abs(x-xx)+abs(y-yy)<<'\n';
			continue;
		}
		int ans=INF;
		if(max(x,y)==max(xx,yy)-1)
		{
			for(int i=0;i<2;i++)
				ans=min(ans,abs(x-cnt[max(x,y)-1][i][0])+abs(y-cnt[max(x,y)-1][i][1])+abs(xx-cnt[max(xx,yy)-2][i][0]-(i==0))+abs(yy-cnt[max(xx,yy)-2][i][1]-(i==1))+1);
		}
		else
		{
			node res=query(1,1,n-2,max(x,y),max(xx,yy)-2);
			for(int i=0;i<2;i++)
				for(int l=0;l<2;l++)
					ans=min(ans,abs(x-cnt[max(x,y)-1][i][0])+abs(y-cnt[max(x,y)-1][i][1])+res.a[i][l]+abs(xx-cnt[max(xx,yy)-2][l][0]-(l==0))+abs(yy-cnt[max(xx,yy)-2][l][1]-(l==1))+1);
		}
		// for(int i=0;i<2;i++)
			// for(int l=0;l<2;l++)
				// cout<<cnt[max(xx,yy)-2][i][l]<<" ";
		// cout<<endl;
		cout<<ans<<'\n';
	}
	return 0;
}