#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int Maxn=300000;
struct Node{
	int ch[26];
	int fail,top;
}node[Maxn+5];
int n,m;
int a[Maxn+5];
multiset<int> val[Maxn+5];
int maxn[Maxn+5];
char s[Maxn+5];
bool vis[Maxn+5];
int pos[Maxn+5];
int Root=1,id_tot=1;
int insert(char *s,int len){
	int root=Root;
	for(int i=1;i<=len;i++){
		if(node[root].ch[s[i]-'a']==0){
			node[root].ch[s[i]-'a']=++id_tot;
		}
		root=node[root].ch[s[i]-'a'];
	}
	vis[root]=1;
	return root;
}
queue<int> q;
void build(){
	for(int i=0;i<26;i++){
		if(node[Root].ch[i]){
			node[node[Root].ch[i]].fail=1;
			q.push(node[Root].ch[i]);
		}
		else{
			node[Root].ch[i]=Root;
		}
	}
	node[Root].top=Root;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[node[u].fail]){
			node[u].top=node[u].fail;
		}
		else{
			node[u].top=node[node[u].fail].top;
		}
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
}
int main(){
	memset(maxn,-1,sizeof maxn);
	vis[Root]=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int len=0;
		while(s[++len]!='\0');
		len--;
		pos[i]=insert(s,len);
		val[pos[i]].insert(0);
		a[i]=0;
		maxn[pos[i]]=0;
	}
	build();
	for(int i=1;i<=m;i++){
		int op;
		scanf("%d",&op);
		if(op==1){
			int x,v;
			scanf("%d%d",&x,&v);
			val[pos[x]].erase(val[pos[x]].find(a[x]));
			a[x]=v;
			val[pos[x]].insert(a[x]);
			maxn[pos[x]]=*--val[pos[x]].end();
		}
		else{
			scanf("%s",s+1);
			int len=0;
			while(s[++len]!='\0');
			len--;
			int root=Root;
			int ans=-1;
			for(int j=1;j<=len;j++){
				root=node[root].ch[s[j]-'a'];
				for(int u=root;u!=1;u=node[u].top){
					ans=max(ans,maxn[u]);
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}