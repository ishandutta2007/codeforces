#include<cstdio> 

using namespace std;

struct lhy{
	int size;
	unsigned long long hash;
}tree[800010];

unsigned long long Pow[200010],Hash,Plus;
int n,m,ans,a[200010],b[200010],where[200010];

inline void up(int k)
{
	tree[k].size=tree[k<<1].size+tree[k<<1|1].size;
	tree[k].hash=tree[k<<1].hash*Pow[tree[k<<1|1].size]+tree[k<<1|1].hash;
}

void insert(int k,int l,int r,int ll)
{
	if(l==r)
	{
		tree[k].size=1;
		tree[k].hash=b[ll];
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)insert(k<<1,l,mid,ll);
	else insert(k<<1|1,mid+1,r,ll);
	up(k);
}

void del(int k,int l,int r,int ll)
{
	if(l==r)
	{
		tree[k].size=0;
		tree[k].hash=0;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)del(k<<1,l,mid,ll);
	else del(k<<1|1,mid+1,r,ll);
	up(k);
}

int main()
{
	Pow[0]=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),Hash=Hash*233+a[i],Pow[i]=Pow[i-1]*233,Plus=Plus*233+1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		where[b[i]]=i;
	}
	for(int i=1;i<n;i++)insert(1,1,m,where[i]);
	for(int i=n;i<=m;i++)
	{
		insert(1,1,m,where[i]);
		if(tree[1].hash==Hash)ans++;
		del(1,1,m,where[i-n+1]);
		Hash+=Plus;
	}
	printf("%d",ans);
}