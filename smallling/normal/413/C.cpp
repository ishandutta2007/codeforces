#include<cstdio>
#include<algorithm>

using namespace std;

struct lhy{
	int num,val;
}a[1001];

int n,m,o;
long long ans;

int cmp(lhy a,lhy b)
{
	if(a.num!=b.num)return a.num<b.num;
	return a.val>b.val;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].val);
	for(int i=1;i<=m;i++)
		scanf("%d",&o),a[o].num=1;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	if(!a[i].num)ans+=1ll*a[i].val;
	else ans+=max(1ll*a[i].val,ans);
	printf("%I64d",ans);
}