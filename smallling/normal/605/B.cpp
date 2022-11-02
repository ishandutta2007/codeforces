#include<cstdio>
#include<algorithm>

#define N 100010
#define fi first
#define se second
#define mp make_pair

using namespace std;

struct lhy{
	int l,f,id;
}a[N];

int n,m,nowl,l,cnt;
pair<int,int>ans[N],q[N];

inline int cmp(const lhy &a,const lhy &b)
{
	if(a.l!=b.l)return a.l<b.l;
	return a.f>b.f;
}

int main()
{
	scanf("%d%d",&n,&m);
	int mN=n;
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a[i].l,&a[i].f),a[i].id=i;
	sort(a+1,a+1+m,cmp);
	n=1;
	for(int i=1;i<=m;i++)
	{
		if(!a[i].f)
		{
			cnt++;
			if(cnt>l)return puts("-1"),0;
			ans[a[i].id]=mp(q[cnt].fi,q[cnt].se);
		}
		else
		{
			n++;
			if(n>mN)return puts("-1"),0;
			ans[a[i].id]=mp(n-1,n);
			for(int j=1;j<n-1&&l<=m;j++)q[++l]=mp(j,n);
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d %d\n",ans[i].fi,ans[i].se);
}