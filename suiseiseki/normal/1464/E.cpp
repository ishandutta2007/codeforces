#include <cstdio>
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
int max(int a,int b){
	return a>b?a:b;
}
const int Maxv=1000;
const int Maxn=100000;
const int Mod=998244353;
const int inv_2=(Mod+1)>>1;
int n,m;
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
int qu[Maxn+5],qu_f,qu_t;
int deg[Maxn+5];
int sg[Maxn+5];
int max_sg,len;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
void init_bfs(){
	for(int i=1;i<=n;i++){
		if(deg[i]==0){
			qu[++qu_t]=i;
		}
	}
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			deg[v]--;
			if(deg[v]==0){
				qu[++qu_t]=v;
			}
		}
	}
}
void init_sg(){
	static bool vis[Maxv+5];
	for(int i=qu_t;i>0;i--){
		int u=qu[i];
		for(int j=head[u];j;j=nxt[j]){
			int v=arrive[j];
			vis[sg[v]]=1;
		}
		while(vis[sg[u]]){
			sg[u]++;
		}
		max_sg=max(max_sg,sg[u]);
		for(int j=head[u];j;j=nxt[j]){
			int v=arrive[j];
			vis[sg[v]]=0;
		}
	}
}
int f[Maxn+5];
void FWT_xor(int *a,int flag,int len){
	for(int i=1;i<len;i<<=1){
		for(int j=0;j<len;j+=(i<<1)){
			for(int k=0;k<i;k++){
				int Nx=a[j+k],Ny=a[i+j+k];
				a[j+k]=(Nx+Ny)%Mod;
				a[i+j+k]=(Nx-Ny+Mod)%Mod;
				if(flag==-1){
					a[j+k]=1ll*a[j+k]*inv_2%Mod;
					a[i+j+k]=1ll*a[i+j+k]*inv_2%Mod;
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		deg[v]++;
		add_edge(u,v);
	}
	init_bfs();
	init_sg();
	int inv_n_1=quick_power(n+1,Mod-2,Mod);
	len=1;
	while(len<=max_sg){
		len<<=1;
	}
	for(int i=1;i<=n;i++){
		f[sg[i]]++;
	}
	for(int i=0;i<len;i++){
		int tmp=1ll*inv_n_1*f[i]%Mod;
		f[i]=(0-tmp+Mod)%Mod;
	}
	f[0]++;
	FWT_xor(f,1,len);
	for(int i=0;i<len;i++){
		f[i]=quick_power(f[i],Mod-2,Mod);
	}
	FWT_xor(f,-1,len);
	int ans=1ll*f[0]*inv_n_1%Mod;
	ans=(1-ans+Mod)%Mod;
	printf("%d\n",ans);
	return 0;
}