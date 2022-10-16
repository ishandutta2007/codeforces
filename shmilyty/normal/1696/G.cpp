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
const double inf=1e9;
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
	double a[3][3];
}t[800001];
node operator+(node x,node y)
{
	node z={-inf,-inf,-inf,-inf,-inf,-inf,-inf,-inf,-inf};
	for(int i=0;i<3;i++)
		for(int l=0;l<3;l++)
			for(int j=0;j<3;j++)
				z.a[i][l]=max(z.a[i][l],x.a[i][j]+y.a[j][l]);
	return z;
}
int n,q,X,Y;
void build(int x,int l,int r)
{
	if(l==r)
	{
		int v=read();
		t[x]={0,1.0*v/(1.0*X+Y),1.0*v/(1.0*Y),0,1.0*v/(1.0*X+Y),-inf,0,-inf,-inf};
		// for(int i=0;i<3;i++)
			// for(int j=0;j<3;j++)
				// cout<<t[x].a[i][j]<<" \n"[j==2];
		return ;
	}
	int mid=(l+r)>>1,xx=x<<1;
	build(xx,l,mid);
	build(xx|1,mid+1,r);
	t[x]=t[xx]+t[xx|1];
}
void modify(int x,int l,int r,int p,int v)
{
	if(l==r)
	{
		t[x]={0,1.0*v/(1.0*X+Y),1.0*v/(1.0*Y),0,1.0*v/(1.0*X+Y),-inf,0,-inf,-inf};
		return ;
	}
	int mid=(l+r)>>1,xx=x<<1;
	if(p<=mid)
		modify(xx,l,mid,p,v);
	else
		modify(xx|1,mid+1,r,p,v);
	t[x]=t[xx]+t[xx|1];
}
node query(int x,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr)
		return t[x];
	int mid=(l+r)>>1,xx=x<<1;
	if(ll>mid)
		return query(xx|1,mid+1,r,ll,rr);
	if(mid>=rr)
		return query(xx,l,mid,ll,rr);
	return query(xx,l,mid,ll,rr)+query(xx|1,mid+1,r,ll,rr);
}
signed main()
{
	n=read();
	q=read();
	X=read();
	Y=read();
	if(X>Y)
		swap(X,Y);
	build(1,1,n);
	while(q--)
	{
		int opt=read();
		if(opt&1)
		{
			int x=read(),y=read();
			modify(1,1,n,x,y);
		}
		else
		{
			int l=read(),r=read();
			node res=query(1,1,n,l,r);
			printf("%.10lf\n", max({res.a[0][0],res.a[0][1],res.a[0][2]}));
		}
	}
	return 0;
}