#include<stdio.h>
#define MAXN 110000
using namespace std;
int cnt[MAXN];
int f[MAXN];
int n;
int ask(int v)
{
	int reu=0;
	for(;v;v-=v&-v)if(cnt[v]>reu)reu=cnt[v];
	return reu;
}
void insert(int x,int v)
{
	for(;x<=n;x+=x&-x)if(v>cnt[x])cnt[x]=v;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int v;scanf("%d",&v);
		f[i]=ask(v-1)+1;
		insert(v,f[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(f[i]>ans)ans=f[i];
	printf("%d\n",ans);
	return 0;
}