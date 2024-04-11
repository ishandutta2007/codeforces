#include<bits/stdc++.h>
#define pb push_back
#define ls (rt<<1)
#define rs ((rt<<1)|1)
using namespace std;
const int N=2050,inf=1e8,V=(N<<2);
int n,K,l,r,ans=0,bas=0;
char s[N][N];
struct Act
{
	int l,r,typ;
};
vector<Act> vec[N];
struct Segment_tree
{
	int tag[V],vmx[V];
	void cover(int rt,int w)
	{
		tag[rt]+=w;
		vmx[rt]+=w;
	}
	void mdown(int rt)
	{
		cover(ls,tag[rt]);
		cover(rs,tag[rt]);
		tag[rt]=0;
	}
	void mup(int rt)
	{
		vmx[rt]=max(vmx[ls],vmx[rs]);
	}
	void update(int rt,int l,int r,int x,int y,int w)
	{
		if(l>=x&&r<=y)
		{
			cover(rt,w);
			return ;
		}
		int mid=(l+r)>>1;
		mdown(rt);
		if(mid>=x) update(ls,l,mid,x,y,w);
		if(mid<y) update(rs,mid+1,r,x,y,w);
		mup(rt);
	}
}sgt;
int main()
{
	int i,j,vsi,a,b;
	Act bno;
	scanf("%d%d",&n,&K);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
	}
	for(i=1;i<=n;i++)
	{
		l=inf;r=-inf;
		for(j=1;j<=n;j++)
		{
			if(s[i][j]=='B')
			{
				l=min(l,j);r=max(r,j);
			}
		}
		if(l<=r&&r-l+1<=K)
		{
			
			a=max(1,r-K+1);b=l;
			//printf("S%d %d %d\n",max(i-K+1,1),a,b);
			vec[max(i-K+1,1)].pb((Act){a,b,1});
			vec[i+1].pb((Act){a,b,-1});
		}
		if(l>r) bas++; 
	}
	for(j=1;j<=n;j++)
	{
		l=inf;r=-inf;
		for(i=1;i<=n;i++)
		{
			if(s[i][j]=='B')
			{
				l=min(l,i);r=max(r,i);
			}
		}
		if(l<=r&&r-l+1<=K)
		{
			//printf("S%d\n",j);
			a=max(1,r-K+1);b=l;
			//printf("H%d %d %d\n",a,max(j-K+1,1),j);
			vec[a].pb((Act){max(j-K+1,1),j,1});
			vec[b+1].pb((Act){max(j-K+1,1),j,-1});
		}
		if(l>r) bas++;
	}
	for(i=1;i<=n;i++)
	{
		vsi=vec[i].size();
		for(j=0;j<vsi;j++)
		{
			bno=vec[i][j];
			//printf("update%d %d %d %d\n",i,bno.l,bno.r,bno.typ);
			sgt.update(1,1,n,bno.l,bno.r,bno.typ);
			
			//printf("ans%d\n",ans);
		}
		ans=max(ans,sgt.vmx[1]);
	}
	printf("%d",ans+bas);
	return 0;
}