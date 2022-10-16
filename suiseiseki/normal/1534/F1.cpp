#include <cstdio>
#include <vector>
#include <algorithm>
const int Maxn=400000;
int n,m;
char _s[Maxn+5];
char *s[Maxn+5];
int a[Maxn+5];
int _id[Maxn+5];
int *id[Maxn+5];
int id_tot;
int head[Maxn+5],arrive[Maxn<<2|5],nxt[Maxn<<2|5],tot;
void add_edge(int from,int to){
//	printf("(%d,%d)-->(%d,%d)\n",(from-1)/m+1,(from-1)%m+1,(to-1)/m+1,(to-1)%m+1);
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int pos[Maxn+5],cur[Maxn+5];
int dfn[Maxn+5],low[Maxn+5],dfn_tot;
int col[Maxn+5],col_tot;
int deg[Maxn+5];
bool in_st[Maxn+5];
int st[Maxn+5],top;
void tarjan(int u){
	dfn[u]=low[u]=++dfn_tot;
	st[++top]=u;
	in_st[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(dfn[v]==0){
			tarjan(v);
			low[u]=std::min(low[u],low[v]);
		}
		else if(in_st[v]){
			low[u]=std::min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		col[u]=++col_tot;
		while(st[top]!=u){
			in_st[st[top]]=0;
			col[st[top]]=col[u];
			top--;
		}
		in_st[st[top]]=0;
		top--;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		s[i]=_s+(i-1)*m;
		id[i]=_id+(i-1)*m;
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++){
			id[i][j]=++id_tot;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.'){
				cur[j]=pos[j];
				continue;
			}
			cur[j]=i;
		}
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.'){
				continue;
			}
			if(j>1&&cur[j-1]>0){
				add_edge(id[cur[j-1]][j-1],id[i][j]);
			}
			if(j<m&&cur[j+1]>0){
				add_edge(id[cur[j+1]][j+1],id[i][j]);
			}
			if(pos[j]){
				add_edge(id[pos[j]][j],id[i][j]);
			}
			if(i<n&&s[i+1][j]=='#'){
				add_edge(id[i+1][j],id[i][j]);
			}
		}
		for(int j=1;j<=m;j++){
			pos[j]=cur[j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.'){
				continue;
			}
			if(dfn[id[i][j]]==0){
				tarjan(id[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.'){
				continue;
			}
			int u=id[i][j];
			for(int k=head[u];k;k=nxt[k]){
				int v=arrive[k];
				if(col[v]==col[u]){
					continue;
				}
				deg[col[v]]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=col_tot;i++){
		if(deg[i]==0){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}