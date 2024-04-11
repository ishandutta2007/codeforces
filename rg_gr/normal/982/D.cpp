#include <stdio.h>
#include <queue>
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
int curs,bl,fa[100005],sz[100005],t[100005],a[100005],vis[100005];
int find(int x)
{
	if(fa[x])return fa[x]==x?x:fa[x]=find(fa[x]);
	return 0;
}
inline void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	bl--,t[sz[fx]]--,t[sz[fy]]--;
	if(sz[fx]>sz[fy])fx^=fy^=fx^=fy;
	fa[fx]=fy;sz[fy]+=sz[fx];t[curs=sz[fy]]++;
}
inline void crt(int x)
{
	bl++,fa[x]=x;sz[x]=1;t[1]++,curs=1;
}
inline int ch()
{
	return t[curs]==bl;
}
struct qaq{
	int v,i;
	bool operator<(const qaq& b)const
	{
		return v>b.v;
	}
};
std::priority_queue<qaq> q;
signed main()
{
	int n=read(),ans=0,pos=0;
	for(int i=1;i<=n;i++)q.push((qaq){a[i]=read(),i});
	while(!q.empty())
	{
		qaq x=q.top();q.pop();
		crt(x.i);
		int i=x.i;
		if(find(x.i-1))merge(i,i-1);
		if(find(x.i+1))merge(i,i+1);
		if(ch()&&ans<bl)ans=bl,pos=x.v;
		/*for(int i=1;i<=n;i++)printf("%d ",find(i));
		printf(" | ");
		for(int i=1;i<=n;i++)if(find(i)==i)printf("%d ",sz[i]);
		printf("Bl=%d , x=%d",bl,x.v);
		puts("Steve");*/
	}
	printf("%d\n",pos+1);
}