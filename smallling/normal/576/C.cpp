#include<cstdio>
#include<algorithm>

using namespace std;

struct lhy{
	int x,y,id;
}a[1000010];

int n,X=1000;

inline int cmp(const lhy &a,const lhy &b)
{
	if(a.x/X!=b.x/X)return a.x<b.x;
	if((a.x/X)&1)return a.y<b.y;
	return a.y>b.y;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)printf("%d ",a[i].id);
}