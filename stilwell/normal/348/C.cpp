#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <bitset>
using namespace std;

int n,m,q,i,j,k,u,v;
long long a[100005],b[100005],ans[100005],tmp[100005];
int cnt[100005],son[100005],next[100005],S[100005],tot;
int st[100005],top;
long long val[100005],Ans;
char opt;

map <int,int> Map[100005];
bitset <505> Bit[100005];

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;++i)scanf("%I64d",&a[i]);
	for(i=1;i<=m;++i)
	{
		scanf("%d",&j);
		for(;j;--j)
		{
			scanf("%d",&k);
			++cnt[k];next[++tot]=son[k];son[k]=tot;S[tot]=i;
		}
	}
	tot=0;
	for(i=1;i<=n;++i)
	if(cnt[i]>200)
	{
		++tot;
		for(j=son[i];j;j=next[j])Bit[S[j]][tot]=1;
	}
	else
	{
		for(j=son[i];j;j=next[j])
		for(k=son[i];k;k=next[k])
		++Map[S[j]][S[k]];
	}
	for(i=1;i<=n;++i)
	for(j=son[i];j;j=next[j])
	ans[S[j]]+=a[i];
	for(;q;--q)
	{
		for(opt=getchar();opt!='?'&&opt!='+';opt=getchar());
		if(opt=='?')
		{
			scanf("%d",&u);
			Ans=ans[u];
			for(i=1;i<=top;++i)if(Map[u].find(st[i])!=Map[u].end())Ans+=val[i]*Map[u][st[i]];
			for(i=1;i<=tot;++i)if(Bit[u][i])Ans+=tmp[i];
			printf("%I64d\n",Ans);
		}
		else
		{
			scanf("%d%d",&u,&v);
			st[++top]=u;val[top]=v;
			b[u]+=v;
			for(i=1;i<=tot;++i)if(Bit[u][i])tmp[i]+=v;
		}
		if(top==200)
		{
			for(i=1;i<=n;++i)
			for(j=son[i];j;j=next[j])
			a[i]+=b[S[j]];
			for(i=1;i<=m;++i)ans[i]=b[i]=0;
			for(i=1;i<=tot;++i)tmp[i]=0;
			for(i=1;i<=n;++i)
			for(j=son[i];j;j=next[j])
			ans[S[j]]+=a[i];
			top=0;
		}
	}
}