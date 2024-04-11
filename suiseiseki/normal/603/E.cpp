#include <cstdio>
#include <algorithm>
const int Maxn=100000;
const int Maxm=300000;
struct Edge{
	int u,v,t,w;
}edge[Maxm+5],d[Maxm+5];
int n,m;
int ans[Maxm+5],id[Maxm+5];
bool cmp_Edge(Edge a,Edge b){
	return a.w<b.w;
}
namespace DSU{
	int fa[Maxn+5],sz[Maxn+5];
	int st[Maxn+5],top,tot;
	void init(){
		top=0;
		tot=n;
		for(int i=1;i<=n;i++){
			fa[i]=i;
			sz[i]=1;
		}
	}
	int find(int x){
		if(x==fa[x]){
			return x;
		}
		return find(fa[x]);
	}
	void merge(int x,int y){
		int fa_x=find(x),fa_y=find(y);
		if(fa_x==fa_y){
			return;
		}
		if(sz[fa_x]<sz[fa_y]){
			std::swap(fa_x,fa_y);
			std::swap(x,y);
		}
		fa[fa_y]=fa_x;
		tot-=(sz[fa_x]&1);
		tot-=(sz[fa_y]&1);
		sz[fa_x]+=sz[fa_y];
		tot+=(sz[fa_x]&1);
		st[++top]=fa_y;
	}
	void roll_back(){
		int y=st[top--];
		int x=fa[y];
		tot-=(sz[x]&1);
		sz[x]-=sz[y];
		fa[y]=y;
		tot+=(sz[x]&1);
		tot+=(sz[y]&1);
	}
}
void cdq(int l,int r,int x,int y){
	if(l>r){
		return;
	}
	int mid=(l+r)>>1;
	int pre=DSU::top;
	for(int i=l;i<=mid;i++){
		if(id[i]<x){
			DSU::merge(edge[i].u,edge[i].v);
		}
	}
	for(int i=x;i<=y;i++){
		if(d[i].t<=mid){
			DSU::merge(d[i].u,d[i].v);
		}
		if(DSU::tot==0){
			ans[mid]=i;
			break;
		}
	}
	while(DSU::top>pre){
		DSU::roll_back();
	}
	if(ans[mid]==0){
		for(int i=l;i<=mid;i++){
			if(id[i]<x){
				DSU::merge(edge[i].u,edge[i].v);
			}
		}
		cdq(mid+1,r,x,y);
		while(DSU::top>pre){
			DSU::roll_back();
		}
		return;
	}
	for(int i=l;i<=mid;i++){
		if(id[i]<x){
			DSU::merge(edge[i].u,edge[i].v);
		}
	}
	cdq(mid+1,r,x,ans[mid]);
	while(DSU::top>pre){
		DSU::roll_back();
	}
	for(int i=x;i<ans[mid];i++){
		if(d[i].t<l){
			DSU::merge(d[i].u,d[i].v);
		}
	}
	cdq(l,mid-1,ans[mid],y);
	while(DSU::top>pre){
		DSU::roll_back();
	}
}
int main(){
	scanf("%d%d",&n,&m);
	DSU::init();
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		edge[i].t=i;
		d[i]=edge[i];
	}
	std::sort(d+1,d+1+m,cmp_Edge);
	for(int i=1;i<=m;i++){
		id[d[i].t]=i;
	}
	cdq(1,m,1,m);
	for(int i=1;i<=m;i++){
		if(ans[i]==0){
			puts("-1");
		}
		else{
			printf("%d\n",d[ans[i]].w);
		}
	}
	return 0;
}