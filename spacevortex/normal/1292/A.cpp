#include<bits/stdc++.h>
#define ls (rt<<1)
#define rs ((rt<<1)|1)
using namespace std;
const int N=4e5+50;
int n,Q;
struct Node{int f[2][2];};
Node mrg(Node a,Node b)
{
	Node p;
	int i,j,k;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			p.f[i][j]=0;
			for(k=0;k<2;k++)
			{
				if(a.f[i][k]&&b.f[k][j]) p.f[i][j]=1;
			}
		}
	}
	return p;
}
struct Segment_tree
{
	int val[N][2];
	Node p[N];
	void mup(int rt)
	{
		p[rt]=mrg(p[ls],p[rs]);
	}
	void build(int rt,int l,int r)
	{
		if(l==r)
		{
			val[l][0]=val[l][1]=1;
			p[rt].f[0][0]=p[rt].f[0][1]=p[rt].f[1][0]=p[rt].f[1][1]=1;
			return ;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		mup(rt);
	}
	void chg(int rt,int l,int r,int x,int t)
	{
		if(l==r)
		{
			val[l][t]^=1;
			for(int i=0;i<2;i++)
			{
				for(int j=0;j<2;j++)
				{
					if(val[l][i]&&val[l][j]) p[rt].f[i][j]=1;
					else p[rt].f[i][j]=0;
				}
			}
			return ;
		}
		int mid=(l+r)>>1;
		if(mid>=x) chg(ls,l,mid,x,t);
		else chg(rs,mid+1,r,x,t);
		
		mup(rt);
		//printf("rt %d %d\n",rt,p[rt].f[0][0]);
	}
}sgt;
int main()
{
	int x,y;
	ios::sync_with_stdio(false);
	cin>>n>>Q;
	sgt.build(1,1,n);
	while(Q--)
	{
		cin>>y>>x;y--;
		sgt.chg(1,1,n,x,y);
		if(sgt.p[1].f[0][1]) puts("Yes");
		else puts("No");
	}
	return 0;
}