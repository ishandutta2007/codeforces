#include<cstdio>
#include<cstring>

#define N 100010
#define mo 1000000007

using namespace std;

int n,m,l,r,ans,nowans,val,D,C[6][6];
int tree[N*4][6],lazy[N*4],a[N],Pow[N][6],SPow[6][N];

inline void up(int k)
{
	for(int d=0;d<=5;d++)
	{
		tree[k][d]=tree[k<<1][d]+tree[k<<1|1][d];
		if(tree[k][d]>=mo)tree[k][d]-=mo;
	}
}

void build(int k,int l,int r)
{
	if(l==r)
	{
		tree[k][0]=a[l];
		for(int d=1;d<=5;d++)
			tree[k][d]=1ll*tree[k][d-1]*l%mo;
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	up(k);
}

inline void down(int k,int l,int r)
{
	if(lazy[k]==-1)return;
	lazy[k<<1]=lazy[k<<1|1]=lazy[k];
	int mid=(l+r)>>1;
	for(int d=0;d<=5;d++)
	{
		tree[k<<1][d]=SPow[d][mid]-SPow[d][l-1]+mo;
		if(tree[k<<1][d]>=mo)tree[k<<1][d]-=mo;
		tree[k<<1][d]=1ll*tree[k<<1][d]*lazy[k]%mo;
		tree[k<<1|1][d]=SPow[d][r]-SPow[d][mid]+mo;
		if(tree[k<<1|1][d]>=mo)tree[k<<1|1][d]-=mo;
		tree[k<<1|1][d]=1ll*tree[k<<1|1][d]*lazy[k]%mo;
	}
	lazy[k]=-1;
}

void modify(int k,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr)
	{
		lazy[k]=val;
		for(int d=0;d<=5;d++)
		{
			tree[k][d]=SPow[d][r]-SPow[d][l-1]+mo;
			if(tree[k][d]>=mo)tree[k][d]-=mo;
			tree[k][d]=1ll*tree[k][d]*val%mo;
		}
		return;
	}
	int mid=(l+r)>>1;
	down(k,l,r);
	if(mid>=ll)modify(k<<1,l,mid,ll,rr);
	if(mid<rr)modify(k<<1|1,mid+1,r,ll,rr);
	up(k);
}

void ask(int k,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr)
	{
		nowans+=tree[k][D];
		if(nowans>=mo)nowans-=mo;
		return;
	}
	int mid=(l+r)>>1;
	down(k,l,r);
	if(mid>=ll)ask(k<<1,l,mid,ll,rr);
	if(mid<rr)ask(k<<1|1,mid+1,r,ll,rr);
}

int main()
{
	memset(lazy,-1,sizeof(lazy));
	C[0][0]=1;
	for(int i=1;i<=5;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		Pow[i][0]=1;
		for(int d=1;d<=5;d++)
			Pow[i][d]=1ll*Pow[i][d-1]*i%mo;
	}
	for(int d=0;d<=5;d++)
		for(int i=1;i<=n;i++)
		{
			SPow[d][i]=SPow[d][i-1]+Pow[i][d];
			if(SPow[d][i]>=mo)SPow[d][i]-=mo;
		}
	Pow[0][0]=1;
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		char ch=getchar();
		while(ch!='?'&&ch!='=')ch=getchar();
		scanf("%d%d%d",&l,&r,&val);
		if(ch=='=')modify(1,1,n,l,r);
		if(ch=='?')
		{
			ans=0;
			for(int d=0;d<=val;d++)
			{
				D=d;
				nowans=0;
				ask(1,1,n,l,r);
				nowans=1ll*nowans*Pow[l-1][val-d]%mo*C[val][d]%mo;
				if((val-d)&1)nowans=-nowans+mo;
				if(nowans>=mo)nowans-=mo;
				ans+=nowans;
				if(ans>=mo)ans-=mo;
			}
			printf("%d\n",ans);
		}
	}
}