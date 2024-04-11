#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=210000;
int sz[N],val[N],lazy[N];
int l[N],r[N],fa[N];int tot;int root;
void down(int x){
	lazy[l[x]]+=lazy[x];
	lazy[r[x]]+=lazy[x];
	val[l[x]]+=lazy[x];
	val[r[x]]+=lazy[x];
	lazy[x]=0;
}
void up(int x){sz[x]=sz[l[x]]+sz[r[x]]+1;}
void left(int x){
	int y=fa[x];int z=fa[y];
	r[y]=l[x];if(l[x])fa[l[x]]=y;
	fa[x]=z;if(l[z]==y)l[z]=x;else r[z]=x;
	fa[y]=x;l[x]=y;up(y);up(x);
}
void right(int x){
	int y=fa[x];int z=fa[y];
	l[y]=r[x];if(r[x])fa[r[x]]=y;
	fa[x]=z;if(l[z]==y)l[z]=x;else r[z]=x;
	fa[y]=x;r[x]=y;up(y);up(x);
}
int q[N];
void splay(int x){
	q[q[0]=1]=x;
	for(int k=x;fa[k];k=fa[k])q[++q[0]]=fa[k];
	per(i,q[0],1)down(q[i]);
	while(fa[x]){
		int y=fa[x];int z=fa[y];
		if(!z){
			if(l[y]==x)right(x);else left(x);
		}
		else{
			if(l[z]==y){
				if(l[y]==x)right(y),right(x);
				else left(x),right(x);
			}
			else{
				if(r[y]==x)left(y),left(x);
				else right(x),left(x);
			}
		}
	}
	root=x;
}
void add(int x,int _v){
	down(x);
	if(_v-sz[l[x]]>val[x]){
		++val[x];if(l[x]){++val[l[x]];++lazy[l[x]];}
		_v-=sz[l[x]]+1;
		if(r[x]==0){
			++tot;val[tot]=_v;sz[tot]=1;fa[tot]=x;r[x]=tot;goto pyc;
		}
		else add(r[x],_v);
	}
	else{
		if(l[x]==0){
			++tot;val[tot]=_v;sz[tot]=1;fa[tot]=x;l[x]=tot;goto pyc;
		}
		else add(l[x],_v);
	}
	pyc:;
	up(x);
}
int rt=0;
int ans[N];
void dfs(int x){
	down(x);
	if(l[x])dfs(l[x]);
	ans[++rt]=val[x];
	if(r[x])dfs(r[x]);
}
int n;int a[N];
int pre(int x){
	down(x);
	x=l[x];down(x);
	while(r[x]){
		x=r[x];
		down(x);
	}
	return x;
}
int suf(int x){
	down(x);
	x=r[x];down(x);
	while(l[x]){
		x=l[x];
		down(x);
	}
	return x;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	root=0;
	per(i,n,1){
		if(root==0){
			tot=1;sz[tot]=1;val[tot]=a[i];root=1;
			continue;
		}
		add(root,a[i]);
		splay(tot);
		if(l[root])if(val[pre(root)]>val[root]){
			printf(":(\n");return 0;
		}
		
		if(r[root])if(val[suf(root)]<val[root]){
			printf(":(\n");return 0;
		}
	}
	dfs(root);
	rep(i,1,n-1)if(ans[i]>ans[i+1]){printf(":(\n");return 0;}
	rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}