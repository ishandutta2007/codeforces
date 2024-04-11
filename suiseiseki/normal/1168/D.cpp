#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 150000
#define ll long long
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
int fa[Maxn+5],s[Maxn+5];
bool leaf[Maxn+5];
int id[Maxn+5],dep[Maxn+5],mx_dep;
int sum[Maxn+5],cnt[Maxn+5][26],f[Maxn+5][26];
vector<int> g[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
char qu[3];
int n,q;
void init_dfs_1(int u){
	dep[u]=dep[fa[u]]+1;
	if(dep[u]>mx_dep){
		mx_dep=dep[u];
	}
	leaf[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		leaf[u]=0;
		init_dfs_1(v);
	}
}
void init_dfs_2(int u){
	id[u]=u;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		init_dfs_2(v);
		if(id[u]==u){
			id[u]=id[v];
		}
		else{
			id[u]=u;
		}
	}
	if(u==1){
		id[u]=u;
	}
	if(id[u]==u&&u!=0){
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			fa[id[v]]=u;
			g[u].push_back(id[v]);
		}
	}
}
int num;
void update(int u,int c,int w){
	cnt[u][c]+=w;
	for(int i=fa[u];i;i=fa[i]){
		if(sum[i]>dep[i]){
			num--;
		}
		sum[i]-=f[i][c];
		f[i][c]=0;
		for(int j=0;j<(int)g[i].size();j++){
			int v=g[i][j];
			f[i][c]=mx(f[i][c],f[v][c]+cnt[v][c]);
		}
		sum[i]+=f[i][c];
		if(sum[i]>dep[i]){
			num++;
		}
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){
		scanf("%d%s",&fa[i],qu);
		s[i]=(*qu);
		add_edge(fa[i],i);
	}
	init_dfs_1(1);
	for(int i=1;i<=n;i++){
		if(leaf[i]){
			if(dep[i]!=mx_dep){
				while(q--){
					puts("Fou");
				}
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		dep[i]=mx_dep-dep[i];
	}
	init_dfs_2(1);
	for(int i=2;i<=n;i++){
		if(s[i]!='?'){
			update(id[i],s[i]-'a',1);
		}
	}
	int u;
	ll ans;
	while(q--){
		scanf("%d%s",&u,qu);
		if(s[u]!='?'){
			update(id[u],s[u]-'a',-1);
		}
		s[u]=(*qu);
		if(s[u]!='?'){
			update(id[u],s[u]-'a',1);
		}
		if(num>0){
			puts("Fou");
		}
		else{
			printf("Shi ");
			ans=0;
			for(int i=0;i<26;i++){
				ans+=1ll*(i+1)*(f[1][i]+dep[1]-sum[1]);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}