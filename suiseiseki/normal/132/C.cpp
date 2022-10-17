#include <cstdio>
#include <cstring>
#define Maxn 100
int f[Maxn+5][Maxn+5][2];
int g[Maxn+5][Maxn+5][2];
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int ab(int a){
	return a<0?-a:a;
}
char s[Maxn+5];
int main(){
	int n,m;
	scanf("%s",s+1);
	n=0;
	while(s[++n]!='\0');
	n--;
	scanf("%d",&m);
	int now;
	memset(f,-0x3f,sizeof f);
	memset(g,0x3f,sizeof g);
	f[1][0][0]=g[1][0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<2;k++){
				now=(k==0)?1:-1;
				if(s[i]=='F'){
					f[i+1][j][k]=mx(f[i+1][j][k],f[i][j][k]+now);
					g[i+1][j][k]=mn(g[i+1][j][k],g[i][j][k]+now);
					f[i+1][j+1][k^1]=mx(f[i+1][j+1][k^1],f[i][j][k]);
					g[i+1][j+1][k^1]=mn(g[i+1][j+1][k^1],g[i][j][k]);
				}
				else{
					f[i+1][j+1][k]=mx(f[i+1][j+1][k],f[i][j][k]+now);
					g[i+1][j+1][k]=mn(g[i+1][j+1][k],g[i][j][k]+now);
					f[i+1][j][k^1]=mx(f[i+1][j][k^1],f[i][j][k]);
					g[i+1][j][k^1]=mn(g[i+1][j][k^1],g[i][j][k]);
				}
			}
		}
	}
	int ans_max=(-1<<30),ans_min=(1<<30);
	for(int i=(m&1);i<=m;i+=2){
		ans_max=mx(ans_max,mx(f[n+1][i][0],f[n+1][i][1]));
		ans_min=mn(ans_min,mn(g[n+1][i][0],g[n+1][i][1]));
	}
	printf("%d\n",mx(ab(ans_max),ab(ans_min)));
	return 0;
}