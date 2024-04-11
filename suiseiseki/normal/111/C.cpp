#include <cstdio>
#include <cstring>
int f[45][(1<<7)|5][(1<<7)|5];
int mn(int a,int b){
	return a<b?a:b;
}
bool vis[45];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==1&&m==1){
		puts("0");
		return 0;
	}
	if(n<m){
		n^=m^=n^=m;
	}
	memset(f,0x3f,sizeof f);
	int tot;
	for(int i=0;i<(1<<m);i++){
		tot=0;
		for(int j=1;j<=m;j++){
			if(i&(1<<(j-1))){
				tot++;
			}
		}
		f[1][0][i]=tot;
	}
	int ans=(1<<30);
	bool flag;
	for(int i=2;i<=n;i++){
		for(int j=0;j<(1<<m);j++){
			for(int k=0;k<(1<<m);k++){
				tot=0;
				for(int l=1;l<=m;l++){
					if(j&(1<<(l-1))){
						tot++;
					}
				}
				for(int l=0;l<(1<<m);l++){
					memset(vis,0,sizeof vis);
					for(int p=1;p<=m;p++){
						if(l&(1<<(p-1))){
							vis[p]=1;
						}
						if(j&(1<<(p-1))){
							vis[p]=1;
						}
						if(k&(1<<(p-1))){
							vis[p-1]=vis[p]=vis[p+1]=1;
						}
					}
					flag=0;
					for(int p=1;p<=m;p++){
						if(!vis[p]){
							flag=1;
							break;
						}
					}
					if(flag){
						continue;
					}
					f[i][k][j]=mn(f[i][k][j],f[i-1][l][k]+tot);
					if(i==n){
						memset(vis,0,sizeof vis);
						for(int p=1;p<=m;p++){
							if(k&(1<<(p-1))){
								vis[p]=1;
							}
						}
						for(int p=1;p<=m;p++){
							if(j&(1<<(p-1))){
								vis[p-1]=vis[p]=vis[p+1]=1;
							}
						}
						flag=0;
						for(int p=1;p<=m;p++){
							if(!vis[p]){
								flag=1;
								break;
							}
						}
						if(flag){
							continue;
						}
						ans=mn(ans,f[i][k][j]);
					}
				}
			}
		}
	}
	printf("%d\n",n*m-ans);
	return 0;
}