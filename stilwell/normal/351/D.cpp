#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,s1,s2;
int col[100005],last[100005],pre[100005],fail[100005];
int sum1[100005],sum2[100005],ans[100005];

struct node
{
	int l,r,id;
}t[100005];
inline bool cmp(const node &a,const node &b){return a.r<b.r;}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&col[i]);
		pre[i]=last[col[i]];
		last[col[i]]=i;
		if(i-pre[i]==pre[i]-pre[pre[i]])fail[i]=fail[pre[i]];
		else fail[i]=pre[pre[i]];
	}
	scanf("%d",&m);
	for(i=1;i<=m;++i)scanf("%d%d",&t[i].l,&t[i].r),t[i].id=i;
	sort(t+1,t+m+1,cmp);
	k=1;
	for(i=1;i<=n;++i)
	{
		for(j=i;j;j-=j&-j)++sum1[j];
		for(j=pre[i];j;j-=j&-j)--sum1[j];
		for(j=fail[i];j;j-=j&-j)++sum2[j];
		for(j=fail[pre[i]];j;j-=j&-j)--sum2[j];
		for(;k<=m&&t[k].r==i;++k)
		{
			s1=s2=0;
			for(j=t[k].l;j<=n;j+=j&-j)s1+=sum1[j],s2+=sum2[j];
			ans[t[k].id]=s1+(s1==s2);
		}
	}
	for(i=1;i<=m;++i)printf("%d\n",ans[i]);
}