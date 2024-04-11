#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
const int Maxb=330;
int n,q;
std::string s[Maxn+5];
int pos[Maxn+5];
struct Trie_Node{
	int ch[26];
	int fail;
}node[Maxn+5];
int id_tot;
int add_string(std::string s){
	int root=0;
	for(int i=0;i<(int)s.size();i++){
		if(node[root].ch[s[i]-'a']==0){
			node[root].ch[s[i]-'a']=++id_tot;
		}
		root=node[root].ch[s[i]-'a'];
	}
	return root;
}
int qu[Maxn+5],qu_f,qu_t;
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
int dfn[Maxn+5],sz[Maxn+5],dfn_tot;
int f[Maxn+5];
void add(int x,int a){
	for(int i=x;i<=dfn_tot;i+=(i&(-i))){
		f[i]+=a;
	}
}
void add(int l,int r,int a){
	add(l,a);
	add(r+1,-a);
}
int query(int x){
	int ans=0;
	for(int i=x;i>0;i-=(i&(-i))){
		ans+=f[i];
	}
	return ans;
}
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
void init_dfs(int u){
	sz[u]=1;
	dfn[u]=++dfn_tot;
	for(int i=head[u];i!=-1;i=nxt[i]){
		int v=arrive[i];
		init_dfs(v);
		sz[u]+=sz[v];
	}
}
void init_fail(){
	qu_f=1,qu_t=0;
	for(int i=0;i<26;i++){
		if(node[0].ch[i]){
			node[node[0].ch[i]].fail=0;
			qu[++qu_t]=node[0].ch[i];
		}
	}
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		for(int i=0;i<26;i++){
			if(node[u].ch[i]){
				node[node[u].ch[i]].fail=node[node[u].fail].ch[i];
				qu[++qu_t]=node[u].ch[i];
			}
			else{
				node[u].ch[i]=node[node[u].fail].ch[i];
			}
		}
	}
	memset(head,-1,sizeof head);
	for(int i=1;i<=id_tot;i++){
		add_edge(node[i].fail,i);
	}
	init_dfs(0);
}
ll ans[Maxn+5];
std::vector<std::pair<std::pair<int,int>,int> > qu_1[Maxn+5];
std::vector<std::pair<int,int> > qu_2[Maxn+5];
int sum[Maxn+5];
void work_1_dfs(int u){
	for(int i=head[u];i!=-1;i=nxt[i]){
		int v=arrive[i];
		work_1_dfs(v);
		sum[u]+=sum[v];
	}
}
ll val[Maxn+5];
void work_1(int x){
	memset(sum,0,sizeof sum);
	int u=0;
	for(int i=0;i<(int)s[x].size();i++){
		u=node[u].ch[s[x][i]-'a'];
		sum[u]++;
	}
	work_1_dfs(0);
	for(int i=1;i<=n;i++){
		val[i]=val[i-1]+sum[pos[i]];
	}
	for(int i=0;i<(int)qu_1[x].size();i++){
		ans[qu_1[x][i].second]=val[qu_1[x][i].first.second]-val[qu_1[x][i].first.first-1];
	}
}
void work_2(){
	for(int i=1;i<=n;i++){
		add(dfn[pos[i]],dfn[pos[i]]+sz[pos[i]]-1,1);
		for(int j=0;j<(int)qu_2[i].size();j++){
			ll num=0;
			int u=0;
			for(int k=0;k<(int)s[qu_2[i][j].first].size();k++){
				u=node[u].ch[s[qu_2[i][j].first][k]-'a'];
				num+=query(dfn[u]);
			}
			if(qu_2[i][j].second>0){
				ans[qu_2[i][j].second]+=num;
			}
			else{
				ans[-qu_2[i][j].second]-=num;
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		static char ch[Maxn+5];
		scanf("%s",ch);
		s[i]=ch;
		pos[i]=add_string(s[i]);
	}
	init_fail();
	for(int i=1;i<=q;i++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		if((int)s[k].size()>=Maxb){
			qu_1[k].push_back(std::make_pair(std::make_pair(l,r),i));
		}
		else{
			qu_2[l-1].push_back(std::make_pair(k,-i));
			qu_2[r].push_back(std::make_pair(k,i));
		}
	}
	for(int i=1;i<=n;i++){
		if((int)s[i].size()>=Maxb){
			work_1(i);
		}
	}
	work_2();
	for(int i=1;i<=q;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
}