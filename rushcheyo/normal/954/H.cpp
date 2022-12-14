#include<cstdio>
const int N=5005,P=1000000007;
int n,a[N],c[N],f[N][N*2],ans[N*2];
int main(){
	scanf("%d",&n);
	for(int i=c[0]=1;i<n;i++)scanf("%d",a+i),c[i]=1ll*c[i-1]*a[i]%P;
	for(int i=n;i;i--){
		f[i][0]=1;
		for(int j=1;j<=n-i;j++){
			f[i][j]=1ll*f[i+1][j-1]*a[i]%P;
			ans[j]=(ans[j]+1ll*f[i][j]*c[i-1])%P;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+n-2;j;j--){
			f[i][j]=f[i-1][j-1];
			if(i>1&&j>1&&j-2<=n-i)f[i][j]=(f[i][j]+f[i][j-2]*(a[i-1]-1ll))%P;
			ans[j]=(ans[j]+1ll*f[i][j]*c[i-1])%P;
		}
	for(int i=1;i<=2*n-2;i++)printf("%d%c",int(ans[i]*(P+1ll)/2%P)," \n"[i==2*n-2]);
	return 0;
}