#include <cstdio>
#include <algorithm>
using namespace std;
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
const int Maxn=105;
int n,m,Mod;
char s[Maxn+5][Maxn+5];
int id[Maxn+5][Maxn+5],id_tot;
int pos[Maxn*Maxn+5];
int fa[Maxn*Maxn+5];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	fa[fa_y]=fa_x;
}
struct Matrix{
	int n;
	int a[Maxn*5+5][Maxn*5+5];
	void add_edge(int u,int v){
		a[u][u]++;
		a[v][v]++;
		a[u][v]--;
		a[v][u]--;
	}
	int solve(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=(a[i][j]+Mod)%Mod;
			}
		}
		int ans=1;
		for(int i=1;i<n;i++){
			int pos=i;
			while(pos<n&&a[pos][i]==0){
				pos++;
			}
			if(pos>=n){
				continue;
			}
			if(pos!=i){
				ans=Mod-ans;
				swap(a[pos],a[i]);
			}
			int tmp=quick_power(a[i][i],Mod-2,Mod);
			for(int j=i+1;j<n;j++){
				int now=1ll*tmp*a[j][i]%Mod;
				for(int k=i;k<n;k++){
					a[j][k]=(a[j][k]-1ll*a[i][k]*now%Mod+Mod)%Mod;
				}
			}
		}
		for(int i=1;i<n;i++){
			ans=1ll*ans*a[i][i]%Mod;
		}
		return ans;
	}
}g[2];
int main(){
	scanf("%d%d%d",&n,&m,&Mod);
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=m+1;j++){
			id[i][j]=++id_tot;
			fa[id[i][j]]=id[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++){
			if(s[i][j]=='*'){
				continue;
			}
			if(s[i][j]=='\\'){
				merge(id[i][j],id[i+1][j+1]);
			}
			else{
				merge(id[i][j+1],id[i+1][j]);
			}
		}
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=m+1;j++){
			if(find(id[i][j])==id[i][j]){
				g[(i+j)&1].n++;
				pos[id[i][j]]=g[(i+j)&1].n;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='*'){
				g[(i+j)&1].add_edge(pos[find(id[i][j])],pos[find(id[i+1][j+1])]);
				g[(i+j+1)&1].add_edge(pos[find(id[i+1][j])],pos[find(id[i][j+1])]);
			}
		}
	}
	printf("%d\n",(g[0].solve()+g[1].solve())%Mod);
	return 0;
}