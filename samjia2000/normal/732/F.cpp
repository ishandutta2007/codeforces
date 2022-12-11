#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;

const int N = 4e+5+10;

struct edge{
	int x,nxt,id;
}e[N*2];
struct road{
	int x,y;
}way[N];
bool bz[N],pd[N];
int be[N],u,dfn[N],r[N],k,f[N],sta[N],top,h[N],tot;
int n,m,ans,ki,tp,nv;

void inse(int x,int y,int id){
	e[++tot].x=y;
	e[tot].nxt=h[x];
	e[tot].id=id;
	h[x]=tot;
}

void tarjan(int x,int fa){
	dfn[x]=f[x]=++k;
	sta[++top]=x;
	pd[x]=1;
	for(int p=h[x];p;p=e[p].nxt)
		if (e[p].id!=fa){
			if (!dfn[e[p].x]){
				bz[e[p].id]=1;
				tarjan(e[p].x,e[p].id);
				f[x]=min(f[x],f[e[p].x]);
			}
			else if (pd[e[p].x])f[x]=min(f[x],dfn[e[p].x]);
		}
	pd[x]=0;
	r[x]=k;
	if (dfn[x]==f[x]){
		nv=1;
		u++;
		while(sta[top]!=x){
			nv++;
			be[sta[top]]=u;
			pd[sta[top--]]=0;
		}
		be[x]=u;
		top--;
		if (nv>ans){
			ans=nv;
			ki=u;
			tp=dfn[x];
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&way[i].x,&way[i].y);
		inse(way[i].x,way[i].y,i);
		inse(way[i].y,way[i].x,i);
	}
	for(int i=1;i<=n;i++)
		if (!dfn[i])tarjan(i,0);
	printf("%d\n",ans);
	for(int i=1;i<=m;i++){
		if (dfn[way[i].x]>dfn[way[i].y])swap(way[i].x,way[i].y);
		if (be[way[i].x]==be[way[i].y]&&be[way[i].x]==ki){
			if (bz[i])printf("%d %d\n",way[i].x,way[i].y);
			else printf("%d %d\n",way[i].y,way[i].x);
		}
		else{
			if (dfn[way[i].y]<=tp&&tp<=r[way[i].y])printf("%d %d\n",way[i].x,way[i].y);
			else printf("%d %d\n",way[i].y,way[i].x);
		}
	}
	return 0;
}