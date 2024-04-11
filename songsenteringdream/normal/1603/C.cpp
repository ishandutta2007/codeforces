#include<cstdio>
using namespace std;
const int o=1e5+10,MOD=998244353;
int T,n,a[o],b[o];long long ans,f[o];
void upd(int i){
	if(i>n) return;
	int B=a[i]/((a[i]+b[i-1]-1)/b[i-1]);
	if(B^b[i]) b[i]=B,upd(i+1);
	f[i]=f[i+1]+(a[i]-1)/b[i-1]*(n-i+1ll);
}
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=0){
		scanf("%d",&n);f[n+1]=0;
		for(int i=n;i;--i) scanf("%d",&a[i]);
		for(int i=n;i;ans=(ans+f[i--])%MOD) b[i]=a[i],upd(i+1),f[i]=f[i+1];
	}
	return 0;
}