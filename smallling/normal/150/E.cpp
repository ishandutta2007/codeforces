#include<cstdio>
#include<algorithm>

#define N 100010
#define inf 0x3f3f3f3f
#define mp make_pair
#define max(a,b) (a)>(b)?(a):(b)

using namespace std;

struct lhy{
	int x,y,l,next;
}edge[2*N];

struct queue{
	pair<int,int> Qv[N];
	int Ql[N],l,r;
	
	inline void clear()
	{
		l=0,r=-1;
	}
	
	inline void insert(pair<int,int> val,int len)
	{
		while(val.first>=Qv[r].first&&l<=r)r--;
		Qv[++r]=val;Ql[r]=len;
	}
	
	inline pair<int,int> ask(int len)
	{
		while(l<=r&&Ql[l]>len)l++;
		if(l>r)return mp(-inf,0);
		else return Qv[l];
	}
}Q;

int n,l,r,x,y,tot,Time,nowmax,root,fax,Maxdeep,nowval,L,R;
int c[N],son[N],size[N],vis[N],dis[N];
pair<int,int> A[N],B[N],q[N],Ans,ans;

inline void add(int x,int y,int l)
{
	edge[++tot].x=x;edge[tot].y=y;edge[tot].l=l;edge[tot].next=son[x];son[x]=tot;
}

void getroot(int x,int fa,int nsize)
{
	size[x]=1;
	int msize=0,y;
	for(int i=son[x];i;i=edge[i].next)
		if(vis[y=edge[i].y]!=Time&&y!=fa)
		{
			getroot(y,x,nsize);
			size[x]+=size[y];
			msize=max(msize,size[y]);
		}
	msize=max(msize,nsize-size[x]);
	if(msize<nowmax)nowmax=msize,root=x,fax=fa;
}

void getdeep(int x,int fa,int deep)
{
	int y;
	Maxdeep=max(Maxdeep,deep);
	for(int i=son[x];i;i=edge[i].next)
		if(vis[y=edge[i].y]!=Time&&y!=fa)getdeep(y,x,deep+1);
}

void Dfs(int x,int fa,int dis,int deep)
{
	A[deep]=max(A[deep],mp(dis,x));
	for(int i=son[x];i;i=edge[i].next)
		if(vis[y=edge[i].y]!=Time&&y!=fa)Dfs(y,x,dis+((edge[i].l>=nowval)?1:-1),deep+1);
}

int work(int x,int nsize)
{
	nowmax=nsize+1;fax=-1;
	getroot(x,0,nsize);
	x=root;
	vis[x]=Time;
	if(~fax)size[fax]=nsize-size[x];
	int l=0;
	for(int i=son[x];i;i=edge[i].next)
		if(vis[y=edge[i].y]!=Time)
		{
			Maxdeep=0;
			getdeep(y,x,1);
			q[++l]=mp(Maxdeep,y);
			dis[y]=((edge[i].l>=nowval)?1:-1);
		}
	sort(q+1,q+1+l);
	int v,nowdeep,nowl;
	for(int i=0;i<=q[l].first;i++)
		B[i]=mp(-inf,0);
	for(int p=1;p<=l;p++)
	{
		v=q[p].second;
		nowdeep=q[p].first;
		for(int i=0;i<=nowdeep;i++)
			A[i]=mp(-inf,0);
		Dfs(v,x,dis[v],1);
		nowl=q[p-1].first;
		Q.clear();
		for(int i=1;i<=nowdeep;i++)
		{
			while(nowl+i>=L&&nowl)Q.insert(B[nowl],nowl),nowl--;
			if(A[i].first+Q.ask(R-i).first>=0)
				return ans=mp(A[i].second,Q.ask(R-i).second),1;
		}
		for(int i=0;i<=nowdeep;i++)
		{
			B[i]=max(B[i],A[i]);
			if(i>=L&&i<=R&&B[i].first>=0)return ans=mp(x,A[i].second),1;
		}
	}
	for(int i=son[x];i;i=edge[i].next)
		if(vis[y=edge[i].y]!=Time)if(work(y,size[y]))return 1;
	return 0;
}

int main()
{
	scanf("%d%d%d",&n,&L,&R);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&c[i]);
		add(x,y,c[i]),add(y,x,c[i]);
	}
	sort(c+1,c+n);
	c[0]=unique(c+1,c+n)-c-1;
	int l=1,r=c[0];
	while(l<=r)
	{
		int mid=(l+r)>>1;
		nowval=c[mid];
		Time++;
		if(work(1,n))Ans=ans,l=mid+1;
		else r=mid-1;
	}
	printf("%d %d\n",Ans.first,Ans.second);
}