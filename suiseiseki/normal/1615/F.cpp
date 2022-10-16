#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=4000;
const int eps=2003;
const int Mod=1000000007;
int f[2][Maxn+10],g[2][Maxn+10];
// int f[2][Maxn+5][Maxn+5],g[2][Maxn+5][Maxn+5];
int n;
char a[Maxn+5],b[Maxn+5];
void solve(){
	scanf("%d",&n);
	scanf("%s",a+1);
	scanf("%s",b+1);
	/*int cur=0,nxt;
	memset(f[cur],0,sizeof f[cur]);
	memset(g[cur],0,sizeof g[cur]);
	f[cur][0+eps][0+eps]=1;
	for(int i=1;i<=n;i++){
		nxt=cur^1;
		memset(f[nxt],0,sizeof f[nxt]);
		memset(g[nxt],0,sizeof g[nxt]);
		int val=(i&1)?1:-1;
		for(int j=-((i-1)/2);j<=i/2;j++){
			for(int k=-((i-1)/2);k<=i/2;k++){
				if(f[cur][j+eps][k+eps]==0){
					continue;
				}
				if(a[i]!='1'){
					if(b[i]!='1'){
						f[nxt][j+eps][k+eps]=(f[nxt][j+eps][k+eps]+f[cur][j+eps][k+eps])%Mod;
						g[nxt][j+eps][k+eps]=(g[nxt][j+eps][k+eps]+g[cur][j+eps][k+eps]+1ll*f[cur][j+eps][k+eps]*std::abs(j-k))%Mod;
					}
					if(b[i]!='0'){
						f[nxt][j+eps][k+val+eps]=(f[nxt][j+eps][k+val+eps]+f[cur][j+eps][k+eps])%Mod;
						g[nxt][j+eps][k+val+eps]=(g[nxt][j+eps][k+val+eps]+g[cur][j+eps][k+eps]+1ll*f[cur][j+eps][k+eps]*std::abs(j-(k+val)))%Mod;
					}
				}
				if(a[i]!='0'){
					if(b[i]!='1'){
						f[nxt][j+val+eps][k+eps]=(f[nxt][j+val+eps][k+eps]+f[cur][j+eps][k+eps])%Mod;
						g[nxt][j+val+eps][k+eps]=(g[nxt][j+val+eps][k+eps]+g[cur][j+eps][k+eps]+1ll*f[cur][j+eps][k+eps]*std::abs(j+val-k))%Mod;
					}
					if(b[i]!='0'){
						f[nxt][j+val+eps][k+val+eps]=(f[nxt][j+val+eps][k+val+eps]+f[cur][j+eps][k+eps])%Mod;
						g[nxt][j+val+eps][k+val+eps]=(g[nxt][j+val+eps][k+val+eps]+g[cur][j+eps][k+eps]+1ll*f[cur][j+eps][k+eps]*std::abs(j+val-(k+val)))%Mod;
					}
				}
			}
		}
		cur=nxt;
	}
	int ans=0;
	for(int i=-n/2;i<=(n+1)/2;i++){
		ans=(ans+g[cur][i+eps][i+eps])%Mod;
	}
	printf("%d\n",ans);*/
	int cur=0,nxt;
	memset(f[cur],0,sizeof f[cur]);
	memset(g[cur],0,sizeof g[cur]);
	f[cur][0+eps]=1;
	for(int i=1;i<=n;i++){
		nxt=cur^1;
		memset(f[nxt],0,sizeof f[nxt]);
		memset(g[nxt],0,sizeof g[nxt]);
		int val=(i&1)?1:-1;
		for(int j=-i-2;j<=i+2;j++){
			if(f[cur][j+eps]==0&&g[cur][j+eps]==0){
				continue;
			}
			if(a[i]!='1'){
				if(b[i]!='1'){
					f[nxt][j+eps]=(f[nxt][j+eps]+f[cur][j+eps])%Mod;
					g[nxt][j+eps]=(g[nxt][j+eps]+g[cur][j+eps]+1ll*f[cur][j+eps]*std::abs(j))%Mod;
				}
				if(b[i]!='0'){
					f[nxt][j-val+eps]=(f[nxt][j-val+eps]+f[cur][j+eps])%Mod;
					g[nxt][j-val+eps]=(g[nxt][j-val+eps]+g[cur][j+eps]+1ll*f[cur][j+eps]*std::abs(j-val))%Mod;
				}
			}
			if(a[i]!='0'){
				if(b[i]!='1'){
					f[nxt][j+val+eps]=(f[nxt][j+val+eps]+f[cur][j+eps])%Mod;
					g[nxt][j+val+eps]=(g[nxt][j+val+eps]+g[cur][j+eps]+1ll*f[cur][j+eps]*std::abs(j+val))%Mod;
				}
				if(b[i]!='0'){
					f[nxt][j+eps]=(f[nxt][j+eps]+f[cur][j+eps])%Mod;
					g[nxt][j+eps]=(g[nxt][j+eps]+g[cur][j+eps]+1ll*f[cur][j+eps]*std::abs(j))%Mod;
				}
			}
		}
		cur=nxt;
	}
	printf("%d\n",g[cur][0+eps]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}