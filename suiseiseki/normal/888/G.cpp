#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
typedef long long ll;
const int Maxn=200000;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5];
struct Trie_Node{
	int ch[2];
}node[Maxn*30+5];
int Root=1,id_tot=1;
void insert(int val){
	int root=Root;
	for(int i=29;i>=0;i--){
		if(node[root].ch[(val>>i)&1]==0){
			node[root].ch[(val>>i)&1]=++id_tot;
		}
		root=node[root].ch[(val>>i)&1];
	}
}
int query(int root_1,int root_2,int dep){
	if(dep==-1){
		return 0;
	}
	if(root_1==0||root_2==0){
		return Inf;
	}
	if((node[root_1].ch[0]&&node[root_2].ch[0])||(node[root_1].ch[1]&&node[root_2].ch[1])){
		return min(query(node[root_1].ch[0],node[root_2].ch[0],dep-1),query(node[root_1].ch[1],node[root_2].ch[1],dep-1));
	}
	return min(query(node[root_1].ch[0],node[root_2].ch[1],dep-1),query(node[root_1].ch[1],node[root_2].ch[0],dep-1))+(1<<dep);
}
ll ans;
void work_dfs(int u=Root,int dep=29){
	if(dep==-1||u==0){
		return;
	}
	work_dfs(node[u].ch[0],dep-1);
	work_dfs(node[u].ch[1],dep-1);
	if(node[u].ch[0]&&node[u].ch[1]){
		ans+=(1<<dep)+query(node[u].ch[0],node[u].ch[1],dep-1);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		insert(a[i]);
	}
	work_dfs();
	printf("%lld\n",ans);
	return 0;
}