#include <vector>
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=300000;
int n;
int a[Maxn+5],inv_a[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int dep[Maxn+5],fa[Maxn+5];
int val_a[Maxn+5];
std::vector<int> son[Maxn+5];
bool cmp_val_a(int u,int v){
	return val_a[u]<val_a[v];
}
void init_dfs_1(int u){
	val_a[u]=a[u];
	dep[u]=dep[fa[u]]+1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		son[u].push_back(v);
		fa[v]=u;
		init_dfs_1(v);
		val_a[u]=std::min(val_a[u],val_a[v]);
	}
}
int lis_1[Maxn+5],lis_1_len;
int lis_2[Maxn+5],lis_2_len;
int dfn[Maxn+5],rnk[Maxn+5],dfn_tot;
void init_dfs_2(int u){
	lis_1[++lis_1_len]=u;
	dfn[u]=++dfn_tot;
	rnk[dfn[u]]=u;
	for(int i=0;i<(int)son[u].size();i++){
		init_dfs_2(son[u][i]);
	}
	lis_2[++lis_2_len]=u;
}
bool cmp_dfn(int u,int v){
	return dfn[u]<dfn[v];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		inv_a[a[i]]=i;
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	init_dfs_1(1);
	for(int i=1;i<=n;i++){
		std::sort(son[i].begin(),son[i].end(),cmp_val_a);
	}
	init_dfs_2(1);
	ll ans_val=0;
	int pos_l=0;
	while(pos_l+1<=n){
		pos_l++;
		ans_val+=dep[inv_a[pos_l]]-1;
		if(inv_a[pos_l]!=lis_2[pos_l]){
			break;
		}
	}
	if(pos_l<n){
		int pos_r=n;
		while(pos_r>0){
			if(a[lis_1[pos_r]]==pos_r){
				pos_r--;
			}
			else{
				break;
			}
		}
		if(pos_r>pos_l){
			std::vector<int> lis;
			for(int i=pos_l;i<=pos_r;i++){
				lis.push_back(inv_a[i]);
			}
			std::sort(lis.begin(),lis.end(),cmp_dfn);
			for(int i=1;i<(int)lis.size();i++){
				if(fa[lis[i]]!=lis[i-1]){
					puts("NO");
					return 0;
				}
			}
			std::vector<int>::iterator it=std::find(lis.begin(),lis.end(),inv_a[pos_l]);
			lis.erase(it);
			for(int i=1;i<(int)lis.size();i++){
				if(a[lis[i-1]]>=a[lis[i]]){
					puts("NO");
					return 0;
				}
			}
		}
	}
	puts("YES");
	printf("%lld\n",ans_val);
	for(int i=1;i<=n;i++){
		printf("%d ",dfn[i]);
	}
	puts("");
	return 0;
}