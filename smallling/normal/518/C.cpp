#include<cstdio>
#include<algorithm>

using namespace std;

long long ans;
int n,m,k,a[100010],b[100010],c[100010];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),c[a[i]]=i;
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	for(int i=1;i<=m;i++)
	{
		int p=c[b[i]];
		ans+=p/k+(p%k?1:0);
		if(p==1)continue;
		int t=a[p-1];
		swap(a[p-1],a[p]);
		swap(c[b[i]],c[t]);
	}
	printf("%I64d\n",ans);
}