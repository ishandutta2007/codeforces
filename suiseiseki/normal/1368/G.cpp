#include <vector>
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
int n,m;
int find_id(int x,int y){
	if(x<1||y<1||x>n||y>m){
		return 0;
	}
	return (x-1)*m+y;
}
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
struct Edge{
	int u,u_fa,v,v_fa;
	Edge(int _u=0,int _u_fa=0,int _v=0,int _v_fa=0){
		u=_u,v=_v;
		u_fa=_u_fa,v_fa=_v_fa;
	}
}edge[Maxn+5];
int len;
int fa[Maxn+5];
int dfn[Maxn+5],sz[Maxn+5],dfn_tot;
int top[Maxn+5];
void init_dfs(int u){
	if(fa[u]==0){
		top[u]=u;
	}
	else{
		top[u]=top[fa[u]];
	}
	dfn[u]=++dfn_tot;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		fa[v]=u;
		init_dfs(v);
		sz[u]+=sz[v];
	}
}
std::vector<std::pair<int,int> > get_range(int u,int v){
	std::vector<std::pair<int,int> > lis;
	if(v==0){
		lis.push_back(std::make_pair(dfn[top[u]],dfn[top[u]]+sz[top[u]]-1));
	}
	else if(v==fa[u]){
		lis.push_back(std::make_pair(dfn[u],dfn[u]+sz[u]-1));
	}
	else{
		if(dfn[top[u]]<=dfn[v]-1){
			lis.push_back(std::make_pair(dfn[top[u]],dfn[v]-1));
		}
		if(dfn[v]+sz[v]<=dfn[top[u]]+sz[top[u]]-1){
			lis.push_back(std::make_pair(dfn[v]+sz[v],dfn[top[u]]+sz[top[u]]-1));
		}
	}
	return lis;
}
struct Square{
	int x,a;
	int l,r;
	Square(int _x=0,int _l=0,int _r=0,int _a=0){
		x=_x;
		l=_l;
		r=_r;
		a=_a;
	}
};
std::vector<Square> sq_lis;
void print_square(int l_1,int r_1,int l_2,int r_2){
	if(l_1>l_2){
		std::swap(l_1,l_2);
		std::swap(r_1,r_2);
	}
	// printf("%d %d %d %d\n",l_1,r_1,l_2,r_2);
	sq_lis.push_back(Square(l_1,l_2,r_2,1));
	sq_lis.push_back(Square(r_1+1,l_2,r_2,-1));
}
struct Segment_Node{
	int min_val,min_num;
	int lazy;
}seg[Maxn<<2|5];
void build(int root=1,int left=1,int right=n*m){
	seg[root].min_num=right-left+1;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
}
void update_tag(int root,int a){
	seg[root].lazy+=a;
	seg[root].min_val+=a;
}
void push_down(int root){
	if(seg[root].lazy){
		update_tag(root<<1,seg[root].lazy);
		update_tag(root<<1|1,seg[root].lazy);
		seg[root].lazy=0;
	}
}
void push_up(int root){
	seg[root].min_val=std::min(seg[root<<1].min_val,seg[root<<1|1].min_val);
	seg[root].min_num=0;
	if(seg[root<<1].min_val==seg[root].min_val){
		seg[root].min_num+=seg[root<<1].min_num;
	}
	if(seg[root<<1|1].min_val==seg[root].min_val){
		seg[root].min_num+=seg[root<<1|1].min_num;
	}
}
void update(int l,int r,int a,int root=1,int left=1,int right=n*m){
	if(l>right||r<left){
		return;
	}
	if(l<=left&&r>=right){
		update_tag(root,a);
		return;
	}
	push_down(root);
	int mid=(left+right)>>1;
	update(l,r,a,root<<1,left,mid);
	update(l,r,a,root<<1|1,mid+1,right);
	push_up(root);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		static char s[Maxn+5];
		scanf("%s",s+1);
		for(int j=1;j<=m;j++){
			if(s[j]=='L'){
				if(j+2<=m){
					add_edge(find_id(i,j),find_id(i,j+2));
					add_edge(find_id(i,j+2),find_id(i,j));
				}
				edge[++len]=Edge(find_id(i,j),find_id(i,j+2),find_id(i,j+1),find_id(i,j-1));
			}
			else if(s[j]=='R'){
				if(j-2>0){
					add_edge(find_id(i,j),find_id(i,j-2));
					add_edge(find_id(i,j-2),find_id(i,j));
				}
			}
			else if(s[j]=='U'){
				if(i+2<=n){
					add_edge(find_id(i,j),find_id(i+2,j));
					add_edge(find_id(i+2,j),find_id(i,j));
				}
				edge[++len]=Edge(find_id(i,j),find_id(i+2,j),find_id(i+1,j),find_id(i-1,j));
			}
			else{
				if(i-2>0){
					add_edge(find_id(i,j),find_id(i-2,j));
					add_edge(find_id(i-2,j),find_id(i,j));
				}
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(dfn[i]==0){
			init_dfs(i);
		}
	}
	for(int i=1;i<=len;i++){
		std::vector<std::pair<int,int> > lis_1=get_range(edge[i].u,edge[i].u_fa),lis_2=get_range(edge[i].v,edge[i].v_fa);
		for(std::pair<int,int> it_1:lis_1){
			for(std::pair<int,int> it_2:lis_2){
				print_square(it_1.first,it_1.second,it_2.first,it_2.second);
			}
		}
	}
	std::sort(sq_lis.begin(),sq_lis.end(),[](Square a,Square b){return a.x<b.x;});
	ll ans=0;
	std::vector<Square>::iterator it=sq_lis.begin();
	build();
	for(int i=1;i<=n*m;i++){
		while(it!=sq_lis.end()&&(it->x)<=i){
			update(it->l,it->r,it->a);
			it++;
		}
		if(seg[1].min_val!=0){
			ans+=n*m;
		}
		else{
			ans+=n*m-seg[1].min_num;
		}
	}
	printf("%lld\n",ans);
	return 0;
}