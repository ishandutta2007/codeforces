#include <cstdio>
double min(double a,double b){
	return a<b?a:b;
}
const int Maxn=100;
const int Maxv=10000;
int n,x,sum;
int a[Maxn+5];
double f[Maxn+5][Maxv+5];
int main(){
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	f[0][0]=1.0;
	for(int i=1;i<=n;i++){
		for(int j=i;j>0;j--){
			for(int k=a[i];k<=sum;k++){
				f[j][k]+=f[j-1][k-a[i]]*j/(n-j+1);
			}
		}
	}
	double ans=0.0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			ans+=f[i][j]*min(1.0*(n+i)*x,j*2)/i;
		}
	}
	printf("%.10lf\n",ans/2);
	return 0;
}