#include <string>
#include <cstdio>
using namespace std;
typedef long long ll;
const int Maxn=100000;
int n,k;
char s[Maxn+5];
int pos[Maxn+5];
string a[Maxn+5];
namespace SAM{
	struct Node{
		int ch[26];
		int fa,len;
	}node[Maxn<<1|5];
	int id_tot=1;
	int add_ch(int val,int last){
		int p=last;
		int np=++id_tot;
		node[np].len=node[p].len+1;
		for(;p&&node[p].ch[val]==0;p=node[p].fa){
			node[p].ch[val]=np;
		}
		if(p==0){
			node[np].fa=1;
		}
		else{
			int q=node[p].ch[val];
			if(node[q].len==node[p].len+1){
				node[np].fa=q;
			}
			else{
				int nq=++id_tot;
				node[nq]=node[q];
				node[nq].len=node[p].len+1;
				node[q].fa=node[np].fa=nq;
				for(;p&&node[p].ch[val]==q;p=node[p].fa){
					node[p].ch[val]=nq;
				}
			}
		}
		return np;
	}
	int last[Maxn<<1|5];
	int sum[Maxn<<1|5];
	int c[Maxn<<1|5];
	void update(int x,int i){
		for(;x&&last[x]!=i;x=node[x].fa){
			last[x]=i;
			sum[x]++;
		}
	}
	bool vis[Maxn<<1|5];
	void init_dfs(int u){
		if(u==1||vis[u]){
			return;
		}
		vis[u]=1;
		init_dfs(node[u].fa);
		c[u]+=c[node[u].fa];
	}
	void init(){
		for(int i=2;i<=id_tot;i++){
			c[i]=node[i].len-node[node[i].fa].len;
			if(sum[i]<k){
				c[i]=0;
			}
		}
		for(int i=1;i<=id_tot;i++){
			init_dfs(i);
		}
	}
}
namespace Trie{
	struct Trie_Node{
		int ch[26];
		int pos;
	}node[Maxn+5];
	int id_tot=1;
	int add_string(char *s,int len){
		int root=1;
		for(int i=1;i<=len;i++){
			if(node[root].ch[s[i]-'a']==0){
				node[root].ch[s[i]-'a']=++id_tot;
			}
			root=node[root].ch[s[i]-'a'];
		}
		return root;
	}
	int qu[Maxn+5],qu_f,qu_t;
	void build(){
		node[1].pos=1;
		qu_f=1,qu_t=0;
		qu[++qu_t]=1;
		while(qu_f<=qu_t){
			int u=qu[qu_f++];
			for(int i=0;i<26;i++){
				if(node[u].ch[i]){
					int v=node[u].ch[i];
					node[v].pos=SAM::add_ch(i,node[u].pos);
					qu[++qu_t]=v;
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int len=0;
		while(s[++len]!='\0');
		len--;
		pos[i]=Trie::add_string(s,len);
		for(int j=1;j<=len;j++){
			a[i]+=s[j];
		}
	}
	Trie::build();
	for(int i=1;i<=n;i++){
		int u=1;
		for(int j=0;j<(int)a[i].size();j++){
			u=SAM::node[u].ch[a[i][j]-'a'];
			SAM::update(u,i);
		}
	}
	SAM::init();
	for(int i=1;i<=n;i++){
		int u=1;
		ll ans=0;
		for(int j=0;j<(int)a[i].size();j++){
			u=SAM::node[u].ch[a[i][j]-'a'];
			ans+=SAM::c[u];
		}
		printf("%lld ",ans);
	}
	puts("");
	return 0;
}