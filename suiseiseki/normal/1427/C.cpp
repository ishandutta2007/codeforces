#include <cstdio>
#include <cstring>
int max(int a,int b){
	return a>b?a:b;
}
int abs(int a){
	return a<0?-a:a;
}
const int Maxn=100000;
int r,n;
int t[Maxn+5],x[Maxn+5],y[Maxn+5];
int f[Maxn+5],g[Maxn+5];
int main(){
	scanf("%d%d",&r,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&t[i],&x[i],&y[i]);
	}
	memset(f,-0x3f,sizeof f);
	f[0]=0;
	x[0]=y[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i&&j<=(r<<1);j++){
			if(t[i]-t[i-j]>=(r<<1)){
				f[i]=max(f[i],g[i-j]+1);
				break;
			}
			if(t[i]-t[i-j]>=abs(x[i]-x[i-j])+abs(y[i]-y[i-j])){
				f[i]=max(f[i],f[i-j]+1);
			}
		}
		g[i]=max(g[i-1],f[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}