#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
const int Maxn=400000;
const int Inf=0x3f3f3f3f;
int n,m;
char _s[Maxn+5];
char *s[Maxn+5];
int a[Maxn+5];
int _id[Maxn+5];
int *id[Maxn+5];
int id_tot;
int head[Maxn+5],arrive[Maxn<<2|5],nxt[Maxn<<2|5],tot;
void add_edge(int from,int to){
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
int val_l[Maxn+5],val_r[Maxn+5];
std::vector<int> g[Maxn+5];
void add_pos(int x,int l,int r){
	if(val_l[x]==0){
		val_l[x]=l,val_r[x]=r;
		return;
	}
	val_l[x]=std::min(val_l[x],l);
	val_r[x]=std::max(val_r[x],r);
}
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
int qu[Maxn+5],qu_f,qu_t;
struct Segment{
	int l,r;
	Segment(int _l=0,int _r=0){
		l=_l,r=_r;
	}
	friend bool operator <(Segment a,Segment b){
		return a.r<b.r;
	}
}seg[Maxn+5];
int seg_len;
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
				g[col[u]].push_back(col[v]);
			}
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(s[i][j]=='.'){
				continue;
			}
			int u=id[i][j];
			add_pos(col[u],j,j);
			break;
		}
	}
	qu_f=1,qu_t=0;
	for(int i=1;i<=col_tot;i++){
		if(deg[i]==0){
			qu[++qu_t]=i;
		}
	}
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		for(int i=0;i<(int)g[u].size();i++){
			int v=g[u][i];
			add_pos(v,val_l[u],val_r[u]);
			deg[v]--;
			if(deg[v]==0){
				qu[++qu_t]=v;
			}
		}
	}
	for(int j=1;j<=m;j++){
		if(a[j]==0){
			continue;
		}
		int num=0;
		for(int i=n;i>0;i--){
			if(s[i][j]=='.'){
				continue;
			}
			num++;
			if(num==a[j]){
				seg[++seg_len]=Segment(val_l[col[id[i][j]]],val_r[col[id[i][j]]]);
				break;
			}
		}
	}
	std::sort(seg+1,seg+1+seg_len);
	int pos=-1;
	int ans=0;
	for(int i=1;i<=seg_len;i++){
		if(pos<seg[i].l){
			pos=seg[i].r;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}