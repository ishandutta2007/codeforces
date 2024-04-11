#include <cstdio>
#include <cstring>
const int Maxn=750;
const int Maxv=10000000;
int n;
bool g[Maxn+5][Maxn+5];
char s[Maxv+5];
struct AC_Automaton{
	struct Trie_Node{
		int ch[2];
		int id,fa;
		int fail;
	}node[Maxv+5];
	int pos[Maxn+5];
	int id_tot;
	void insert(char *s,int n,int id){
		int root=1;
		for(int i=1;i<=n;i++){
			if(node[root].ch[s[i]-'a']==0){
				node[root].ch[s[i]-'a']=++id_tot;
				node[id_tot].fa=root;
			}
			root=node[root].ch[s[i]-'a'];
		}
		node[root].id=id;
		pos[id]=root;
	}
	int qu[Maxv+5],qu_f,qu_t;
	void build_fail(){
		qu_f=1,qu_t=0;
		node[1].fail=1;
		for(int i=0;i<2;i++){
			if(node[1].ch[i]){
				qu[++qu_t]=node[1].ch[i];
				node[node[1].ch[i]].fail=1;
			}
		}
		while(qu_f<=qu_t){
			int u=qu[qu_f++];
			for(int i=0;i<2;i++){
				if(node[u].ch[i]){
					node[node[u].ch[i]].fail=node[node[u].fail].ch[i];
					qu[++qu_t]=node[u].ch[i];
				}
				else{
					node[u].ch[i]=node[node[u].fail].ch[i];
				}
			}
		}
	}
	int t_fa[Maxv+5];
	int find(int x){
		if(x==t_fa[x]){
			return x;
		}
		return t_fa[x]=find(t_fa[x]);
	}
	void build_trans(){
		for(int i=1;i<=id_tot;i++){
			t_fa[i]=node[i].id?i:node[i].fail;
		}
		for(int i=1;i<=n;i++){
			int x=pos[i];
			if(node[find(node[x].fail)].id){
				g[i][node[find(node[x].fail)].id]=1;
			}
			x=node[pos[i]].fa;
			while(x){
				if(node[x].id){
					g[i][node[x].id]=1;
					break;
				}
				if(node[find(x)].id){
					g[i][node[find(x)].id]=1;
				}
				x=node[x].fa;
			}
		}
	}
	AC_Automaton(){
		id_tot=1;
	}
}tree;
int match_1[Maxn+5],match_2[Maxn+5];
bool vis[Maxn+5];
bool find_match(int x){
	if(vis[x]){
		return 0;
	}
	vis[x]=1;
	for(int i=1;i<=n;i++){
		if(g[x][i]&&(!match_1[i]||find_match(match_1[i]))){
			match_1[i]=x;
			return 1;
		}
	}
	return 0;
}
bool vis_1[Maxn+5],vis_2[Maxn+5];
void work_dfs(int x){
	if(vis_1[x]){
		return;
	}
	vis_1[x]=1;
	for(int i=1;i<=n;i++){
		if(g[x][i]&&match_2[x]!=i&&!vis_2[i]){
			vis_2[i]=1;
			if(match_1[i]){
				work_dfs(match_1[i]);
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int len=0;
		while(s[++len]!='\0');
		len--;
		tree.insert(s,len,i);
	}
	tree.build_fail();
	tree.build_trans();
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(g[i][k]&&g[k][j]){
					g[i][j]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		find_match(i);
	}
	for(int i=1;i<=n;i++){
		if(match_1[i]){
			match_2[match_1[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(match_2[i]==0){
			work_dfs(i);
		}
	}
	int num=0;
	for(int i=1;i<=n;i++){
		if(vis_1[i]&&!vis_2[i]){
			num++;
		}
	}
	printf("%d\n",num);
	for(int i=1;i<=n;i++){
		if(vis_1[i]&&!vis_2[i]){
			printf("%d ",i);
		}
	}
	puts("");
	return 0;
}