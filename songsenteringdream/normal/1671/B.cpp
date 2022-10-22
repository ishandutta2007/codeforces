#include<cstdio>
using namespace std;
const int o=2e5+10;
int T,n,x[o];bool f[o][3];
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&x[i]);
		f[1][0]=f[1][1]=f[1][2]=1;
		for(int i=2;i<=n;++i) for(int j=0;j<3;++j)
			for(int k=f[i][j]=0;k<3;++k) f[i][j]|=(f[i-1][k]&&x[i]+j==x[i-1]+k+1);
		printf((f[n][0]||f[n][1]||f[n][2])?"YES\n":"NO\n");
	}
	return 0;
}