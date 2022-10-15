#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
struct seg
{
	int l,r,id;
};
seg a[MAXN];
bool cmp(seg x,seg y)
{
	if(x.l!=y.l) return x.l<y.l;
	return x.r>y.r;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)
	{
		if(a[i].r<=a[i-1].r)
		{
			printf("%d %d\n",a[i].id,a[i-1].id);
			return 0;
		}
	}
	puts("-1 -1");
	return 0;
}