#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=200000;
int n;
int a[Maxn+5];
struct Trie_Node{
	int ch[2];
	int sz;
}node[Maxn*30+5];
int id_tot=1;
void insert(int val){
	int root=1;
	for(int i=29;i>=0;i--){
		node[root].sz++;
		if(node[root].ch[(val>>i)&1]==0){
			node[root].ch[(val>>i)&1]=++id_tot;
		}
		root=node[root].ch[(val>>i)&1];
	}
	node[root].sz++;
}
int work_dfs(int u){
	if(node[u].ch[0]==0&&node[u].ch[1]==0){
		return 0;
	}
	if(node[u].ch[0]==0||node[u].ch[1]==0){
		return work_dfs(node[u].ch[0]^node[u].ch[1]);
	}
	int ans=min(work_dfs(node[u].ch[0])+(node[node[u].ch[1]].sz-1),work_dfs(node[u].ch[1])+(node[node[u].ch[0]].sz-1));
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		insert(a[i]);
	}
	printf("%d\n",work_dfs(1));
	return 0;
}