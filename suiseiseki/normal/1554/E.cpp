#include <cstdio>
const int Maxn=100000;
const int Mod=998244353;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int ans[Maxn+5];
int n;
int f[Maxn+5];
bool flag;
void clear_all(){
	tot=0;
	for(int i=1;i<=n;i++){
		head[i]=0;
	}
}
void work_dfs(int u,int fa,int val){
	if(!flag){
		return;
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		work_dfs(v,u,val);
	}
	if(f[u]%val!=0){
		if(fa){
			f[u]++;
		}
		if(f[u]%val!=0){
			flag=0;
			return;
		}
	}
	else{
		f[fa]++;
	}
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	for(int i=1;i<=n;i++){
		ans[i]=0;
	}
	ans[1]=1;
	for(int i=1;i<n;i++){
		ans[1]=(ans[1]<<1)%Mod;
	}
	for(int i=2;i<n;i++){
		if((n-1)%i==0){
			for(int j=0;j<=n;j++){
				f[j]=0;
			}
			flag=1;
			work_dfs(1,0,i);
			ans[i]=flag;
		}
	}
	for(int i=n;i>0;i--){
		for(int j=i+i;j<=n;j+=i){
			ans[i]=(ans[i]-ans[j]+Mod)%Mod;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	clear_all();
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}