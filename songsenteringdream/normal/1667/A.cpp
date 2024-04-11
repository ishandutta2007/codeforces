#include<cstdio>
using namespace std;
const int o=1e4;
int n,a[o];long long b[o],ans=1e18,res;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		b[i]=res=0;
		for(int j=i+1;j<=n;++j) b[j]=(b[j-1]+a[j])/a[j],res+=b[j],b[j]*=a[j];
		for(int j=i-1;j;--j) b[j]=(b[j+1]+a[j])/a[j],res+=b[j],b[j]*=a[j];
		if(res<ans) ans=res;
	}
	printf("%lld",ans);
	return 0;
}