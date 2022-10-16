#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
const int N=2e5+5;
struct p
{
	int id,v;
	p(){}
	p(int a,int b)
	{
		id=a;
		v=b;
	}
};
bool operator < (p a,p b)
{
	if (a.v!=b.v)
		return a.v<b.v;
	return a.id<b.id;
}
map <p,int> AB,CD,BC;
int n1,n2,n3,n4,m1,m2,m3,u,v;
p a[N],b[N],c[N],d[N];
p ab[N],cd[N];
int ans;
int main()
{
	scanf("%d%d%d%d",&n1,&n2,&n3,&n4);
	for (int i=1;i<=n1;i++)
	{
		scanf("%d",&v);
		a[i]=p(i,v);
	}
	for (int i=1;i<=n2;i++)
	{
		scanf("%d",&v);
		b[i]=p(i,v);
	}
	for (int i=1;i<=n3;i++)
	{
		scanf("%d",&v);
		c[i]=p(i,v);
	}
	for (int i=1;i<=n4;i++)
	{
		scanf("%d",&v);
		d[i]=p(i,v);
	}
	sort(a+1,a+n1+1);
	sort(d+1,d+n4+1);
	scanf("%d",&m1);
	for (int i=1;i<=m1;i++)
	{
		scanf("%d%d",&u,&v);
		AB[p(u,v)]=1;
	}
	scanf("%d",&m2);
	for (int i=1;i<=m2;i++)
	{
		scanf("%d%d",&u,&v);
		BC[p(u,v)]=1;
	}
	scanf("%d",&m3);
	for (int i=1;i<=m3;i++)
	{
		scanf("%d%d",&u,&v);
		CD[p(u,v)]=1;
	}
	for (int i=1;i<=n2;i++)
	{
		int cur=1;
		while (AB[p(a[cur].id,i)]&&cur<=n1)
			cur++;
		if (cur<=n1)
			ab[i]=p(i,b[i].v+a[cur].v);
		else
			ab[i]=p(i,1e9);
	}
	for (int i=1;i<=n3;i++)
	{
		int cur=1;
		while (CD[p(i,d[cur].id)]&&cur<=n4)
			cur++;
		if (cur<=n4)
			cd[i]=p(i,c[i].v+d[cur].v);
		else
			cd[i]=p(i,1e9);
	}
	sort(cd+1,cd+n3+1);
	ans=1e9;
	for (int i=1;i<=n2;i++)
	{
		int cur=1;
		while (BC[p(i,cd[cur].id)]&&cur<=n3)
			cur++;
		if (cur<=n3)
			if (ab[i].v+cd[cur].v<=ans)
				ans=ab[i].v+cd[cur].v;
	}
	if (ans>=1e9)
		printf("-1\n");
	else
		printf("%d\n",ans);
	return 0;
}