#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=25,M=4200000;
int n,m,u,v,p[N],f[M],nxt[M],dat[M];

bool check(int s)
{
	rep(i,1,n)
		if(s&(1<<i-1))
			if((s&p[i])!=s)
				return 0;
	return 1;
}

void dfs(int x)
{
	if(!dat[x]) return;
	dfs(nxt[x]),printf("%d ",dat[x]);
}

int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n) p[i]=1<<i-1;
	rep(i,1,m)
	{
		scanf("%d%d",&u,&v);
		p[u]|=(1<<v-1),p[v]|=(1<<u-1);
	}
	memset(f,80,sizeof(f));
	rep(i,1,(1<<n)-1) if(check(i)) f[i]=0;
	rep(i,1,(1<<n)-1)
		rep(j,1,n)
			if(i&(1<<j-1))
				if(f[i|p[j]]>f[i]+1)
					f[i|p[j]]=f[i]+1,nxt[i|p[j]]=i,dat[i|p[j]]=j;
	printf("%d\n",f[(1<<n)-1]);
	dfs((1<<n)-1),puts("");
	return 0;
}