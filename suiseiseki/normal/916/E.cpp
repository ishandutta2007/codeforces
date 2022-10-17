#include <cstdio>
#include <iostream>
using std::cout;
using std::endl;
const int Maxn=100000;
typedef long long ll;
int a[Maxn+5];
int dfn[Maxn+5],end[Maxn+5],rnk[Maxn+5],dfn_tot;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int Root=1;
int n,q;
struct Segment_Node{
	ll sum,lazy;
}seg[Maxn<<2|5];
void build(int root=1,int left=1,int right=n){
	seg[root].lazy=0;
	if(left==right){
		seg[root].sum=a[rnk[left]];
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	seg[root].sum=seg[root<<1].sum+seg[root<<1|1].sum;
}
void update(int l,int r,int a,int root=1,int left=1,int right=n){
	if(l>right||r<left){
		return;
	}
	if(l<=left&&r>=right){
		seg[root].lazy+=a;
		seg[root].sum+=1ll*(right-left+1)*a;
		return;
	}
	int mid=(left+right)>>1;
	update(l,r,a,root<<1,left,mid);
	update(l,r,a,root<<1|1,mid+1,right);
	seg[root].sum=seg[root<<1].sum+seg[root<<1|1].sum+seg[root].lazy*(right-left+1);
}
int mn(int a,int b){
	return a<b?a:b;
}
int mx(int a,int b){
	return a>b?a:b;
}
ll query(int l,int r,int root=1,int left=1,int right=n){
	if(l>right||r<left){
		return 0;
	}
	if(l<=left&&r>=right){
		return seg[root].sum;
	}
	int mid=(left+right)>>1;
	return query(l,r,root<<1,left,mid)+query(l,r,root<<1|1,mid+1,right)+seg[root].lazy*(mn(right,r)-mx(left,l)+1);
}
int fa[17][Maxn+5];
int dep[Maxn+5];
void init_dfs(int u){
	dep[u]=dep[fa[0][u]]+1;
	for(int i=1;fa[i-1][fa[i-1][u]];i++){
		fa[i][u]=fa[i-1][fa[i-1][u]];
	}
	dfn[u]=++dfn_tot;
	rnk[dfn_tot]=u;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[0][u]){
			continue;
		}
		fa[0][v]=u;
		init_dfs(v);
	}
	end[u]=dfn_tot;
}
void swp(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
int unuse_find_lca(int u,int v){
	if(dep[u]<dep[v]){
		swp(u,v);
	}
	for(int i=16;i>=0;i--){
		if(dep[fa[i][u]]>=dep[v]){
			u=fa[i][u];
		}
	}
	if(u==v){
		return u;
	}
	for(int i=16;i>=0;i--){
		if(fa[i][u]!=fa[i][v]){
			u=fa[i][u];
			v=fa[i][v];
		}
	}
	return fa[0][u];
}
int find_lca(int u,int v){
	int lca_1=unuse_find_lca(u,v),lca_2=unuse_find_lca(u,Root),lca_3=unuse_find_lca(v,Root);
	if(dep[lca_1]>=dep[lca_2]&&dep[lca_1]>=dep[lca_3]){
		return lca_1;
	}
	if(dep[lca_2]>=dep[lca_1]&&dep[lca_2]>=dep[lca_3]){
		return lca_2;
	}
	return lca_3;
}
int find_son(int u,int v){
	for(int i=16;i>=0;i--){
		if(dep[fa[i][v]]>dep[u]){
			v=fa[i][v];
		}
	}
	return v;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	init_dfs(1);
	build();
	int op,x;
	for(int i=1;i<=q;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&u);
			Root=u;
		}
		else if(op==2){
			scanf("%d%d%d",&u,&v,&x);
			u=find_lca(u,v);
			if(dfn[u]<=dfn[Root]&&end[u]>=dfn[Root]&&u!=Root){
				v=find_son(u,Root);
				update(1,n,x);
				update(dfn[v],end[v],-x);
			}
			else{
				if(u==Root){
					update(1,n,x);
				}
				else{
					update(dfn[u],end[u],x);
				}
			}
		}
		else{
			scanf("%d",&u);
			if(dfn[u]<=dfn[Root]&&end[u]>=dfn[Root]&&u!=Root){
				v=find_son(u,Root);
				cout<<query(1,n)-query(dfn[v],end[v])<<endl;
			}
			else{
				if(u==Root){
					cout<<query(1,n)<<endl;
				}
				else{
					cout<<query(dfn[u],end[u])<<endl;
				}
			}
		}
	}
	return 0;
}