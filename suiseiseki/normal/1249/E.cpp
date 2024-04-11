#include <cstdio>
#include <cstring>
#define Maxn 200000
int a[Maxn+5];
int b[Maxn+5];
int n,c;
int f[Maxn+5][2];
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d",&b[i]);
	}
	memset(f,0x3f,sizeof f);
	f[1][0]=0;
	for(int i=2;i<=n;i++){
		f[i][0]=mn(f[i][0],f[i-1][0]+a[i-1]);
		f[i][0]=mn(f[i][0],f[i-1][1]+a[i-1]);
		f[i][1]=mn(f[i][1],f[i-1][0]+b[i-1]+c);
		f[i][1]=mn(f[i][1],f[i-1][1]+b[i-1]);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",mn(f[i][0],f[i][1]));
	}
	puts("");
	return 0;
}