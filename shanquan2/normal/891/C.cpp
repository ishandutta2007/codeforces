#include<bits/stdc++.h>
using namespace std;

struct edge{
	int x,y,w;
	bool operator <(const edge &o)const{return w<o.w;}
}e[500005];
int n,m,Q,cnt,fa[500005],fb[500005],ide[500005];
bool cmp(int x,int y){return e[x].w<e[y].w;}
struct fe{
	int k,id;
	bool operator <(const fe &o)const{return e[k].w<e[o.k].w||e[k].w==e[o.k].w&&id<o.id;}
}q[500005];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int findb(int x){
	return fb[x]==x?x:fb[x]=findb(fb[x]);
}
bool ans[500005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w),ide[i]=i;
	sort(ide+1,ide+m+1,cmp);
	scanf("%d",&Q);
	memset(ans,1,sizeof(ans));
	for(int i=0;i<Q;i++){
		int k;scanf("%d",&k);
		for(int j=0;j<k;j++){
			int x;scanf("%d",&x);
			q[cnt++]=(fe){x,i};
		}
	}
	sort(q,q+cnt);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,j=1,p=0;i<=m;i=j){
//		for(int i=1;i<=n;i++)printf("%d ",find(i));printf("\n");
		for(;j<=m&&e[ide[i]].w==e[ide[j]].w;j++);
		int r=p;
		for(;r<cnt&&e[q[r].k].w==e[ide[i]].w;r++);
		for(int i=p,j=p;i<r;i=j){
			for(;j<r&&q[j].id==q[i].id;j++);
//			for(int k=i;k<j;k++)printf("%d ",q[k].k);printf("\n");
			for(int k=i;k<j;k++){
				int l=q[k].k,u=e[l].x,v=e[l].y,p=find(u),q=find(v);
				fb[u]=p,fb[p]=p;fb[v]=q,fb[q]=q;
			}
			for(int k=i;k<j;k++){
				int l=q[k].k,u=findb(e[l].x),v=findb(e[l].y);
				if(u==v){
					ans[q[i].id]=0;
					break;
				}else fb[v]=u;
			}
		}
		p=r;
		for(int k=i;k<j;k++){
			int l=ide[k],p=find(e[l].x),q=find(e[l].y);
			if(p!=q)fa[p]=q;
		}
	}
	for(int i=0;i<Q;i++)if(ans[i])printf("YES\n");else printf("NO\n");
	return 0;
}