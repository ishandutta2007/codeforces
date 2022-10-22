#include<cstdio>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int o=1e6;
int T,n,a[o];
int main(){
	for(scanf("%d",&T);T--;putchar('\n')){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<n-2;i+=2) printf("%d %d ",a[i+1]/gcd(a[i+1],a[i]),-a[i]/gcd(a[i+1],a[i]));
		if(n&1)
			if(a[n-1]+a[n]) printf("%d %d %d",a[n-1]+a[n],-a[n-2],-a[n-2]);
			else if(a[n-2]+a[n]) printf("%d %d %d",-a[n-1],a[n-2]+a[n],-a[n-1]);
			else printf("%d %d %d",-a[n],-a[n],a[n-1]+a[n-2]);
		else printf("%d %d",a[n],-a[n-1]);
	}
	return 0;
}