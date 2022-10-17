#include <cstdio>
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
const int Maxn=2000;
const int Mod=998244353;
int n;
int frac[Maxn+5],inv_f[Maxn+5];
int S[Maxn+5][Maxn+5];
void init(){
	frac[0]=1;
	for(int i=1;i<=Maxn;i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv_f[Maxn]=quick_power(frac[Maxn],Mod-2,Mod);
	for(int i=Maxn-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
	S[0][0]=1;
	for(int i=1;i<=Maxn;i++){
		for(int j=1;j<=i;j++){
			S[i][j]=(S[i-1][j-1]+1ll*(i-1)*S[i-1][j])%Mod;
		}
	}
}
int C(int n,int m){
	return 1ll*frac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
int A(int n,int m){
	return 1ll*frac[n]*inv_f[n-m]%Mod;
}
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int a[Maxn+5],b[Maxn+5];
bool vis[Maxn+5];
int in[Maxn+5],out[Maxn+5];
int h;
int cnt_1,cnt_2,cnt_3;
void dfs_1(int u){
	if(u==0&&vis[u]){
		h++;
		return;
	}
	if(head[u]==0&&u){
		cnt_1++;
		return;
	}
	if(vis[u]){
		return;
	}
	vis[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		dfs_1(v);
	}
}
void dfs_2(int u){
	if(head[u]==0&&u){
		cnt_2++;
		return;
	}
	if(vis[u]){
		return;
	}
	vis[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		dfs_2(v);
	}
}
int dfs_3(int u,int start){
	if(u==start&&vis[u]){
		return 1;
	}
	if(vis[u]){
		return 0;
	}
	vis[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		return dfs_3(v,start);
	}
	return 0;
}
int f[4][Maxn+5];
void work(int *f,int n){
	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
			f[i]=(f[i]+1ll*C(n,j)*S[j][i]%Mod*A(h+n-j,n-j))%Mod;
		}
	}
	for(int i=0;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			if((j-i)&1){
				sum=(sum-1ll*C(j,i)*f[j]%Mod+Mod)%Mod;
			}
			else{
				sum=(sum+1ll*C(j,i)*f[j])%Mod;
			}
		}
		f[i]=sum;
	}
}
int main(){
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++){
		add_edge(a[i],b[i]);
	}
	dfs_1(0);
	for(int i=1;i<=n;i++){
		if(vis[i]){
			in[i]=1;
		}
	}
	tot=0;
	memset(head,0,sizeof head);
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++){
		add_edge(b[i],a[i]);
	}
	dfs_2(0);
	for(int i=1;i<=n;i++){
		if(in[i]){
			vis[i]=1;
			in[i]=0;
		}
	}
	for(int i=1;i<=n;i++){
		in[a[i]]++;
		out[b[i]]++;
	}
	int num=0;
	for(int i=1;i<=n;i++){
		if(in[i]==1&&out[i]==1&&!vis[i]){
			num+=dfs_3(i,i);
		}
	}
	work(f[0],cnt_2);
	work(f[1],cnt_1);
	for(int i=0;i<=n;i++){
		for(int j=i;j>=0;j--){
			f[2][i]=(f[2][i]+1ll*f[0][j]*f[1][i-j])%Mod;
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=i;j>=0;j--){
			f[3][i]=(f[3][i]+1ll*f[2][j]*S[h][i-j])%Mod;
		}
	}
	for(int i=0;i<=n;i++){
		f[3][i]=1ll*f[3][i]*frac[h]%Mod;
	}
	for(int i=0;i<n;i++){
		if(n-i-num>=0){
			printf("%d ",f[3][n-i-num]);
		}
		else{
			printf("0 ");
		}
	}
	puts("");
	return 0;
}