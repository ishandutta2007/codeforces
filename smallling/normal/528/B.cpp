#include<cstdio>
#include<algorithm>

using namespace std;

struct lhy{
	int l,r;
}a[200020];

int ans,n,x,y,l[200020],r[200020],f[200020],c[200020],q[400040];

inline int cmp(const lhy &a,const lhy &b)
{
	if(a.r==b.r)return a.l<b.l;
	return a.r<b.r;
}

int ask(int x)
{
	int nowans=0;
	for(int i=x;i;i-=i&-i)nowans=max(nowans,c[i]);
	return nowans;
}

void up(int x,int val)
{
	for(int i=x;i<=q[0];i+=i&-i)c[i]=max(c[i],val);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		l[i]=x-y;
		r[i]=x+y;
		q[++q[0]]=l[i];
		q[++q[0]]=r[i];
	}
	sort(q+1,q+1+q[0]);
	for(int i=1;i<=n;i++)
		a[i].l=lower_bound(q+1,q+1+q[0],l[i])-q,a[i].r=lower_bound(q+1,q+1+q[0],r[i])-q;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		int now=ask(a[i].l)+1;
		ans=max(ans,now);
		up(a[i].r,now);
	}
	printf("%d",ans);
}