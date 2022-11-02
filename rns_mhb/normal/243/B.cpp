#include<cstdio>
#include<cstdlib>
#include<cstring>
#define N 200005
int n,m,H,T,x,y,l,Mark;
int son[N],ed[N],next[N],v[N],d[N];
void work(int x,int y){
	++Mark;
	int h=0,t=0;
	for (int p=son[x];p;p=next[p]) if (ed[p]!=y) v[ed[p]]=Mark,h++;
	for (int p=son[y];p;p=next[p]) if (ed[p]!=x)
		if (v[ed[p]]!=Mark) t++;
		else if (h>H) v[ed[p]]=0,h--,t++;
	if (h>=H && t>=T){
		printf("YES\n%d %d\n",x,y);
		for (int p=son[x];p && H;p=next[p]) if (ed[p]!=y)
			if (v[ed[p]]==Mark) printf("%d%s",ed[p],--H?" ":"\n");
		for (int p=son[y];p && T;p=next[p]) if (ed[p]!=x)
			if (v[ed[p]]!=Mark) printf("%d%s",ed[p],--T?" ":"\n");
		/*for(;;);*/ exit(0);
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&H,&T);
	for (int i=1;i<=m;i++)
		scanf("%d%d",&x,&y),d[x]++,d[y]++,
		ed[++l]=y,next[l]=son[x],son[x]=l,
		ed[++l]=x,next[l]=son[y],son[y]=l;
	for (int i=1;i<=n;i++) if (d[i]>H)
		for (int p=son[i];p;p=next[p]) if (d[ed[p]]>T) work(i,ed[p]);
	printf("NO\n"); return 0;
}