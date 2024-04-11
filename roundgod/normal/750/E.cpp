#include<bits/stdc++.h>
#define MAXN 200300
#define F first
#define S second
#define INF 1000000000
#define MOD 1000000007
using namespace std;
int n,q;
string S;
int seq[4]={2,0,1,7};
struct node
{
	int l,r;
	int t[5][5];
	void init()
	{
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				t[i][j]=INF;
	}
	void build(int x)
	{
		init();
		for(int i=0;i<5;i++)
		{
			if(i>=3&&x==6)
			{
				t[i][i]=1;
				continue;
			}
			if(i<4&&x==seq[i]) t[i][i+1]=0;
			t[i][i]=(x==seq[i]);
		}
	}
}seg[MAXN*4];
inline node operator +(const node &x, const node &y)
{
	node z;
	z.init();
	z.l=x.l;
	z.r=y.r;
	for(int i=0;i<5;i++)
		for(int j=i;j<5;j++)
			for(int k=j;k<5;k++)
				z.t[i][k]=min(z.t[i][k],x.t[i][j]+y.t[j][k]);
	return z;
}
void build(int k,int l,int r)
{
	seg[k].l=l;
	seg[k].r=r;
	if(l==r) 
	{
		seg[k].build(S[l-1]-'0');
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	seg[k]=seg[k*2]+seg[k*2+1];
}
int f[5],g[5];
void query(int k,int l,int r)
{
	if(seg[k].l>=l&&seg[k].r<=r)
	{
		for(int i=0;i<5;i++)
			g[i]=INF;
		for(int i=0;i<5;i++)
			for(int j=i;j<5;j++)
				g[j]=min(g[j],f[i]+seg[k].t[i][j]);
		for(int i=0;i<5;i++)
			f[i]=g[i];
		return;
	}
	if(seg[k].r<l||seg[k].l>r) return;
	query(k*2,l,r);
	query(k*2+1,l,r);
}
int main()
{
	scanf("%d%d",&n,&q);
	cin>>S;
	build(1,1,n);
	for(int i=0;i<q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		for(int i=1;i<5;i++)
			f[i]=INF;
		f[0]=0;
		query(1,x,y);
		if(f[4]==INF) puts("-1"); else printf("%d\n",f[4]);
	}
	return 0;
}