#include<cstdio>
#include<algorithm>

#define N 400040

using namespace std;

struct lhy{
	int x,y,l,r,id;
}b[N];

int n,m,mN,ans;
int cnt[N],a[N],Ans[N],c[2*N],C[2*N],L[N],R[N],x[2*N]; 

inline void add(int x,int o)
{
	for(;x<=mN;x+=x&-x)c[x]=max(c[x],o);
}

inline int ask(int x)
{
	int nowans=0;
	for(;x;x-=x&-x)nowans=max(nowans,c[x]);
	return nowans;
}

inline void Add(int x,int o)
{
	for(;x;x-=x&-x)C[x]=max(C[x],o); 
}

inline int Ask(int x)
{
	int nowans=0;
	for(;x<=mN;x+=x&-x)nowans=max(nowans,C[x]);
	return nowans;
}

inline int cmp(const lhy &a,const lhy &b)
{
	return a.x<b.x;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),x[++x[0]]=a[i];
	for(int i=1;i<=m;i++)
		scanf("%d%d",&b[i].x,&b[i].y),b[i].id=i,x[++x[0]]=b[i].y;
	sort(x+1,x+1+x[0]);
	mN=unique(x+1,x+1+x[0])-x-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(x+1,x+1+mN,a[i])-x;
	for(int i=1;i<=m;i++)
		b[i].y=lower_bound(x+1,x+1+mN,b[i].y)-x;
	sort(b+1,b+1+m,cmp);
	int now=1;
	for(int i=1;i<=n;i++)
	{
		L[i]=ask(a[i]-1);
		while(b[now].x==i)
		{
			b[now].l=ask(b[now].y-1);
			now++;
		}
		add(a[i],L[i]+1);
	}
	now=m;
	for(int i=n;i;i--)
	{
		R[i]=Ask(a[i]+1);
		while(b[now].x==i)
		{
			b[now].r=Ask(b[now].y+1);
			now--;
		}
		Add(a[i],R[i]+1);
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,L[i]+R[i]+1);
	for(int i=1;i<=n;i++)
		if(L[i]+R[i]+1==ans)cnt[L[i]]++;
	for(int i=1;i<=m;i++)
		if(L[b[i].x]+R[b[i].x]+1<ans||cnt[L[b[i].x]]>1)Ans[b[i].id]=max(ans,b[i].l+b[i].r+1);
		else Ans[b[i].id]=max(ans-1,b[i].l+b[i].r+1);
	for(int i=1;i<=m;i++)
		printf("%d\n",Ans[i]);
}