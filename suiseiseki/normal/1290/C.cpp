#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int Maxn=600000;
const int Inf=(1<<29);
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
void read_1(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	a=(c^48);
}
vector<int> x[Maxn+5];
int len[Maxn+5];
int fa[Maxn+5];
int a[Maxn+5];
int cnt[Maxn+5][2];
int id[Maxn+5][2];
int col[Maxn+5];
int mn(int a,int b){
	return a<b?a:b;
}
int n,k;
int ans;
void dfs(int u){
	cnt[u][col[u]]=1;
	for(int i=0;i<(int)x[u].size();i++){
		int v=id[x[u][i]][0]+id[x[u][i]][1]-u;
		if(v==-1||col[v]!=-1){
			continue;
		}
		col[v]=col[u]^(a[x[u][i]]^1);
		dfs(v);
	}
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void add(int u,int s_0,int s_1){
	u=find(u);
	ans-=mn(cnt[u][0],cnt[u][1]);
	cnt[u][0]=mn(Inf,cnt[u][0]+s_0);
	cnt[u][1]=mn(Inf,cnt[u][1]+s_1);
	ans+=mn(cnt[u][0],cnt[u][1]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	add(fa_x,cnt[fa_y][0],cnt[fa_y][1]);
	add(fa_y,-cnt[fa_y][0],-cnt[fa_y][1]);
	fa[fa_y]=fa_x;
}
int main(){
	read(n),read(k);
	for(int i=1;i<=n;i++){
		read_1(a[i]);
	}
	memset(id,-1,sizeof id);
	int pos;
	for(int i=1;i<=k;i++){
		fa[i]=i;
		read(len[i]);
		for(int j=0;j<len[i];j++){
			read(pos);
			x[i].push_back(pos);
			if(id[pos][0]==-1){
				id[pos][0]=i;
			}
			else{
				id[pos][1]=i;
			}
		}
	}
	memset(col,-1,sizeof col);
	for(int i=1;i<=k;i++){
		if(col[i]==-1){
			col[i]=0;
			dfs(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(id[i][0]!=-1&&id[i][1]==-1){
			if(col[id[i][0]]^(a[i]^1)){
				add(id[i][0],0,Inf);
			}
			else{
				add(id[i][0],Inf,0);
			}
		}
		else if(id[i][0]!=-1){
			merge(id[i][0],id[i][1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}