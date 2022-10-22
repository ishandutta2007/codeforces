#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){ if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
	return x*f;
}
int T;
int n,m;
int a[1010],b[1010];
int f[1010][1010],g[1010][1010];
void dfs(int x,int y){
	if(!x||!y) return ;
	if(g[x][y]==1){
		dfs(x,y-1);
	}
	else if(g[x][y]==2){
		dfs(x-1,y);
	}
	else if(g[x][y]==3) {
		printf("%d ",a[x]);
	}
}
int main(){
	T=read();
	while(T--){
		memset(g,-1,sizeof(g));
		memset(f,0x3f,sizeof(f));
		n=read(),m=read();
		for(int i=1;i<=n;++i) a[i]=read(),f[i][0]=0;
		for(int i=1;i<=m;++i) b[i]=read(),f[0][i]=0;
		f[0][0]=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(f[i][j-1]>0&&f[i][j-1]<f[i][j]){
					f[i][j]=f[i][j-1];g[i][j]=1;
				}
				if(f[i-1][j]>0&&f[i-1][j]<f[i][j]){
					f[i][j]=f[i-1][j];g[i][j]=2;
				}
				if(a[i]==b[j]){
					f[i][j]=1;
					g[i][j]=3;
				}
			}
		}
		if(f[n][m]>=0x3f3f3f3f) printf("NO\n");
		else {
			printf("YES\n");
			printf("%d ",f[n][m]);
			dfs(n,m);
			printf("\n");
		}
	}
	return 0;
}