#include<stdio.h>
int a[200100];
struct edge{
	int t;
	edge *nxt;
	void init(const int _s,const int _t);
}e[400100],*v[200100],*pe=e;
void edge::init(const int _s,const int _t){
	t=_t,nxt=v[_s],v[_s]=this;
}
int n,m;
int lt[2][400200];
inline int getsum(int *lt,int x){
	int ans=0;
	while(x) ans+=lt[x],x-=x&-x;
	return ans;
}
inline void insert(int *lt,int x,int val){
	while(x<=400000) lt[x]+=val,x+=x&-x;
}
int ldfs[200100],rdfs[200100];
bool in[200100];
int dfn=0;
int depth[200100];
void dfs(int x){
	in[x]=1;
	ldfs[x]=++dfn;
	while(v[x]){
		if(!in[v[x]->t]) depth[v[x]->t]=depth[x]^1,dfs(v[x]->t);
		v[x]=v[x]->nxt;
	}
	rdfs[x]=++dfn;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=1;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		pe++->init(x,y);
		pe++->init(y,x);
	}
	dfs(1);
	while(m--){
		int x;
		scanf("%d",&x);
		if(x==1){
			int y,z;
			scanf("%d%d",&y,&z);
			insert(lt[depth[y]],ldfs[y],z);
			insert(lt[depth[y]],rdfs[y],-z);
		}
		else{
			int y;
			scanf("%d",&y);
			printf("%d\n",a[y]+getsum(lt[depth[y]],ldfs[y])-getsum(lt[depth[y]^1],ldfs[y]));
		}
	}
	scanf("%d",&n);
	return 0;
}