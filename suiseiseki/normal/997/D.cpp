#include <cstdio>
#include <cassert>
#include <cstring>
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
const int Maxn=4000;
const int Maxk=37;
const int Mod=998244353;
int n_1,n_2,k;
struct Tree{
	int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
	void add_edge(int from,int to){
		arrive[++tot]=to;
		nxt[tot]=head[from];
		head[from]=tot;
	}
	int f[Maxn+5][Maxk+5],g[Maxn+5][Maxk+5];
	int s[Maxk+5];
	void work_dfs(int u,int fa){
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(v==fa){
				continue;
			}
			work_dfs(v,u);
			for(int j=0;j<=k;j++){
				f[u][j]=(f[u][j]+g[v][j])%Mod;
			}
		}
		s[0]=(s[0]+1)%Mod;
		g[u][0]=1;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=i;j++){
				int x=1ll*f[u][j-1]*g[u][i-j]%Mod;
				g[u][i]=(g[u][i]+x)%Mod;
				s[i]=(s[i]+2ll*j*x)%Mod;
			}
		}
	}
}tree_1,tree_2;
int frac[Maxn<<1|5],inv_f[Maxn<<1|5];
void init(){
	frac[0]=1;
	for(int i=1;i<=(Maxn<<1);i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv_f[Maxn<<1]=quick_power(frac[Maxn<<1],Mod-2,Mod);
	for(int i=(Maxn<<1)-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
}
int C(int n,int m){
	if(m<0||n<m){
		return 0;
	}
	return 1ll*frac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
int main(){
	init();
	scanf("%d%d%d",&n_1,&n_2,&k);
	if(k&1){
		puts("0");
		return 0;
	}
	k>>=1;
	for(int i=1;i<n_1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		tree_1.add_edge(u,v);
		tree_1.add_edge(v,u);
	}
	for(int i=1;i<n_2;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		tree_2.add_edge(u,v);
		tree_2.add_edge(v,u);
	}
	tree_1.work_dfs(1,0);
	tree_2.work_dfs(1,0);
	int ans=0;
	for(int i=0;i<=k;i++){
		ans=(ans+1ll*C(k<<1,i<<1)*tree_1.s[i]%Mod*tree_2.s[k-i])%Mod;
	}
	printf("%d\n",ans);
	return 0;
}