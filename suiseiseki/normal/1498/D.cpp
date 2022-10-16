#include <cstdio>
#include <cstring>
typedef long long ll;
const int Maxn=200;
const int Maxm=100000;
const int Maxd=100000;
int n,m;
int f[Maxm+5],g[Maxm+5];
int main(){
	scanf("%d%d",&n,&m);
	memset(f,-1,sizeof f);
	f[0]=0;
	for(int i=1;i<=n;i++){
		int op,y;
		ll x;
		scanf("%d%lld%d",&op,&x,&y);
		memset(g,0,sizeof g);
		for(int j=0;j<=m;j++){
			if(g[j]==y||f[j]==-1){
				continue;
			}
			if(op==1){
				int tmp=(x-1)/Maxd+1;
				if(j+tmp<=m&&f[j+tmp]==-1){
					f[j+tmp]=i;
					g[j+tmp]=g[j]+1;
				}
			}
			else{
				if(j&&(1ll*j*x-1)/Maxd+1<=m){
					int tmp=(1ll*j*x-1)/Maxd+1;
					if(f[tmp]==-1){
						f[tmp]=i;
						g[tmp]=g[j]+1;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",f[i]);
	}
	puts("");
	return 0;
}