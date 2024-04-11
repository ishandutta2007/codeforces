#include <cstdio>
const int Maxn=300000;
struct AC_automaton{
	struct Trie_Node{
		int ch[26];
		int fail,num,sum;
	}node[Maxn+5];
	int sz[30];
	int st[30],st_top;
	int id_tot;
	void insert(int root,char *s,int len){
		for(int i=1;i<=len;i++){
			if(node[root].ch[s[i]-'a']==0){
				node[root].ch[s[i]-'a']=++id_tot;
			}
			root=node[root].ch[s[i]-'a'];
		}
		node[root].num++;
	}
	int qu[Maxn+5],qu_f,qu_t;
	void build(int root){
		qu_f=1,qu_t=0;
		qu[++qu_t]=root;
		while(qu_f<=qu_t){
			int u=qu[qu_f++];
			node[u].sum=node[node[u].fail].sum+node[u].num;
			for(int i=0;i<26;i++){
				if(node[u].ch[i]==0){
					continue;
				}
				int v=node[u].ch[i];
				node[v].fail=node[u].fail;
				while(node[v].fail&&node[node[v].fail].ch[i]==0){
					node[v].fail=node[node[v].fail].fail;
				}
				if(node[v].fail==0){
					node[v].fail=root;
				}
				else{
					node[v].fail=node[node[v].fail].ch[i];
				}
				qu[++qu_t]=v;
			}
		}
	}
	void _merge_(int &root_1,int root_2){
		if(root_1==0){
			root_1=root_2;
			return;
		}
		if(root_2==0){
			return;
		}
		node[root_1].num+=node[root_2].num;
		for(int i=0;i<26;i++){
			_merge_(node[root_1].ch[i],node[root_2].ch[i]);
		}
	}
	void merge(int &root_1,int root_2){
		_merge_(root_1,root_2);
		build(root_1);
	}
	void add_string(char *s,int len){
		st[++st_top]=++id_tot;
		sz[st_top]=1;
		insert(st[st_top],s,len);
		build(st[st_top]);
		while(st_top>1&&sz[st_top]==sz[st_top-1]){
			merge(st[st_top-1],st[st_top]);
			sz[st_top-1]+=sz[st_top];
			st_top--;
		}
	}
	int query(int root,char *s,int len){
		int Root=root;
		int ans=0;
		for(int i=1;i<=len;i++){
			while(root&&node[root].ch[s[i]-'a']==0){
				root=node[root].fail;
			}
			if(root==0){
				root=Root;
			}
			else{
				root=node[root].ch[s[i]-'a'];
			}
			ans+=node[root].sum;
		}
		return ans;
	}
	int find_ans(char *s,int len){
		int ans=0;
		for(int i=1;i<=st_top;i++){
			ans+=query(st[i],s,len);
		}
		return ans;
	}
	AC_automaton(){
		st_top=0;
		id_tot=0;
	}
}tree_1,tree_2;
char s[Maxn+5];
int len;
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int op;
		scanf("%d",&op);
		if(op==1){
			scanf("%s",s+1);
			len=0;
			while(s[++len]!='\0');
			len--;
			tree_1.add_string(s,len);
		}
		else if(op==2){
			scanf("%s",s+1);
			len=0;
			while(s[++len]!='\0');
			len--;
			tree_2.add_string(s,len);
		}
		else{
			scanf("%s",s+1);
			len=0;
			while(s[++len]!='\0');
			len--;
			int ans=tree_1.find_ans(s,len)-tree_2.find_ans(s,len);
			printf("%d\n",ans);
			fflush(stdout);
		}
	}
	return 0;
}