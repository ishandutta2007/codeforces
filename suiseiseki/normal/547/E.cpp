#include <queue>
#include <cstdio>
using namespace std;
int abs(int a){
	return a<0?-a:a;
}
const int Maxn=200000;
const int Maxq=500000;
int n,q;
char s[Maxn+5];
int pos[Maxn+5];
int dfn[Maxn+5],dfn_tot;
vector<int> edge[Maxn+5];
int sz[Maxn+5];
int k[Maxq+5];
struct Node{
	int ch[26];
	int fail,fa;
}node[Maxn+5];
vector<int> que[Maxn+5];
int id_tot=1;
int insert(int n){
	int root=1;
	for(int i=1;i<=n;i++){
		if(node[root].ch[s[i]-'a']==0){
			node[root].ch[s[i]-'a']=++id_tot;
			node[id_tot].fa=root;
		}
		root=node[root].ch[s[i]-'a'];
	}
	return root;
}
void dfs(int u){
	dfn[u]=++dfn_tot;
	sz[u]=1;
	for(int i=0;i<(int)edge[u].size();i++){
		int v=edge[u][i];
		dfs(v);
		sz[u]+=sz[v];
	}
}
void build(){
	queue<int> q;
	for(int i=0;i<26;i++){
		if(node[1].ch[i]){
			node[node[1].ch[i]].fail=1;
			q.push(node[1].ch[i]);
		}
		else{
			node[1].ch[i]=1;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			if(node[u].ch[i]){
				node[node[u].ch[i]].fail=node[node[u].fail].ch[i];
				q.push(node[u].ch[i]);
			}
			else{
				node[u].ch[i]=node[node[u].fail].ch[i];
			}
		}
	}
	for(int i=2;i<=id_tot;i++){
		edge[node[i].fail].push_back(i);
	}
	dfs(1);
}
int f[Maxn+5];
void add(int x,int a){
	for(int i=x;i<=id_tot;i+=(i&(-i))){
		f[i]+=a;
	}
}
int query(int x){
	int ans=0;
	for(int i=x;i>0;i-=(i&(-i))){
		ans+=f[i];
	}
	return ans;
}
int ans[Maxq+5];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int len=0;
		while(s[++len]!='\0');
		len--;
		pos[i]=insert(len);
	}
	build();
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d%d",&l,&r,&k[i]);
		if(l>1){
			que[l-1].push_back(-i);
		}
		que[r].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int root=pos[i];
		while(root!=1){
			add(dfn[root],1);
			root=node[root].fa;
		}
		for(int j=0;j<(int)que[i].size();j++){
			int id=abs(que[i][j]);
			int x=pos[k[id]];
			if(que[i][j]>0){
				ans[id]+=query(dfn[x]+sz[x]-1)-query(dfn[x]-1);
			}
			else{
				ans[id]-=query(dfn[x]+sz[x]-1)-query(dfn[x]-1);
			}
		}
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}