#include <cstdio>
#include <algorithm>
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Inf=0x3f3f3f3f;
typedef long long ll;
const int Maxn=200000;
int n,id_tot;
int fa[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
namespace Tree_1{
	int sz[Maxn+5],top[Maxn+5],dep[Maxn+5],dfn[Maxn+5],rnk[Maxn+5],son[Maxn+5],dfn_tot;
	int lis[20][Maxn<<1|5],id[Maxn+5],lis_len;
	int log_2[Maxn<<1|5];
	void init_dfs_1(int u){
		dep[u]=dep[fa[u]]+1;
		sz[u]=0;
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(v==fa[u]){
				continue;
			}
			fa[v]=u;
			init_dfs_1(v);
			sz[u]+=sz[v];
			if(son[u]==0||sz[v]>sz[son[u]]){
				son[u]=v;
			}
		}
	}
	void init_dfs_2(int u,int tp){
		dfn[u]=++dfn_tot;
		rnk[dfn[u]]=u;
		top[u]=tp;
		id[u]=++lis_len;
		lis[0][id[u]]=dfn[u];
		if(son[u]){
			init_dfs_2(son[u],tp);
			lis_len++;
			lis[0][lis_len]=dfn[u];
		}
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(v==fa[u]||v==son[u]){
				continue;
			}
			init_dfs_2(v,v);
			lis_len++;
			lis[0][lis_len]=dfn[u];
		}
	}
	void init(){
		init_dfs_1(1);
		init_dfs_2(1,1);
		for(int i=1;(1<<i)<=lis_len;i++){
			for(int j=1;j+(1<<i)-1<=lis_len;j++){
				lis[i][j]=std::min(lis[i-1][j],lis[i-1][j+(1<<(i-1))]);
			}
		}
		log_2[0]=-1;
		for(int i=1;i<=lis_len;i++){
			log_2[i]=log_2[i>>1]+1;
		}
	}
	int find_kth(int u,int k){
		while(dep[u]-dep[top[u]]<k){
			k-=dep[u]-dep[top[u]]+1;
			u=fa[top[u]];
		}
		return rnk[dfn[u]-k];
	}
	int find_lca(int u,int v){
		u=id[u],v=id[v];
		if(u>v){
			std::swap(u,v);
		}
		int k=log_2[v-u+1];
		int ans=std::min(lis[k][u],lis[k][v-(1<<k)+1]);
		return rnk[ans];
	}
	int find_node(int u,int v,int k){
		int lca=find_lca(u,v);
		if(dep[u]-dep[lca]<k){
			return find_kth(v,dep[u]+dep[v]-(dep[lca]<<1)-k);
		}
		return find_kth(u,k);
	}
	int find_dis(int u,int v){
		return dep[u]+dep[v]-(dep[find_lca(u,v)]<<1);
	}
}
struct Circle{
	int u,r;
	Circle(int _u=0,int _r=0){
		u=_u;
		r=_r;
	}
};
int merge_2(Circle a,Circle b){
	int d=Tree_1::find_dis(a.u,b.u);
	if(d+b.r<=a.r){
		return 0;
	}
	if(d+a.r<=b.r){
		return 2;
	}
	return 1;
}
Circle merge_1(Circle a,Circle b){
	int d=Tree_1::find_dis(a.u,b.u);
	if(d+b.r<=a.r){
		return a;
	}
	if(d+a.r<=b.r){
		return b;
	}
	return Circle(Tree_1::find_node(a.u,b.u,(d-a.r+b.r)>>1),(d+a.r+b.r)>>1);
}
namespace Tree_2{
	bool del[Maxn+5];
	int sz[Maxn+5];
	int root,root_val;
	int fa[Maxn+5];
	void get_root(int u,int fa,int all_sz){
		int max_val=0;
		sz[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(del[v]||v==fa){
				continue;
			}
			get_root(v,u,all_sz);
			sz[u]+=sz[v];
			max_val=std::max(max_val,sz[v]);
		}
		max_val=std::max(max_val,all_sz-sz[u]);
		if(max_val<root_val){
			root_val=max_val;
			root=u;
		}
	}
	int init_dfs(int u){
		root=u,root_val=n+1;
		get_root(u,0,Inf);
		get_root(u,0,sz[u]);
		u=root;
		del[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(del[v]){
				continue;
			}
			fa[init_dfs(v)]=u;
		}
		return u;
	}
	void init(){
		init_dfs(1);
	}
	ll sum_dis[Maxn+5],fa_dis[Maxn+5];
	int num[Maxn+5];
	void update(int x,int a){
		int u=x,las=-1;
		while(u){
			int d=Tree_1::find_dis(u,x);
			sum_dis[u]+=a*d;
			num[u]+=a;
			if(las!=-1){
				fa_dis[las]+=a*d;
			}
			las=u;
			u=fa[u];
		}
	}
	ll query(int x){
		int u=x,las=-1;
		ll ans=0;
		while(u){
			int d=Tree_1::find_dis(u,x);
			ans+=(sum_dis[u]-(las==-1?0:fa_dis[las]))+1ll*(num[u]-(las==-1?0:num[las]))*d;
			las=u;
			u=fa[u];
		}
		return ans;
	}
}
Circle val[Maxn+5];
ll solve(int l,int r){
	if(l==r){
		return 0;
	}
	int mid=(l+r)>>1;
	val[mid+1]=Circle(mid+1);
	ll sum_1=0,sum_2=0;
	int num=0;
	for(int i=mid+2;i<=r;i++){
		val[i]=merge_1(val[i-1],Circle(i));
		sum_1+=val[i].r;
	}
	int pos_l=mid+1,pos_r=mid+1;
	ll ans=0;
	for(int i=mid;i>=l;i--){
		if(i!=mid){
			val[i]=merge_1(val[i+1],Circle(i));
		}
		else{
			val[i]=Circle(i);
		}
		while(pos_r<=r&&merge_2(val[pos_r],val[i])!=0){
			Tree_2::update(val[pos_r].u,1);
			sum_1-=val[pos_r].r;
			sum_2+=val[pos_r].r;
			pos_r++;
		}
		while(pos_l<=r&&merge_2(val[pos_l],val[i])==2){
			Tree_2::update(val[pos_l].u,-1);
			num++;
			sum_2-=val[pos_l].r;
			pos_l++;
		}
		ans+=2ll*num*val[i].r+(sum_1<<1)+1ll*(pos_r-pos_l)*val[i].r+sum_2+Tree_2::query(val[i].u);
	}
	while(pos_l<pos_r){
		Tree_2::update(val[pos_l].u,-1);
		pos_l++;
	}
	ans+=solve(l,mid);
	ans+=solve(mid+1,r);
	return ans;
}
int main(){
	read(n);
	id_tot=n;
	for(int i=1;i<n;i++){
		int u,v;
		read(u),read(v);
		id_tot++;
		add_edge(u,id_tot),add_edge(id_tot,u);
		add_edge(id_tot,v),add_edge(v,id_tot);
	}
	Tree_1::init();
	Tree_2::init();
	printf("%lld\n",solve(1,n)>>1);
	return 0;
}