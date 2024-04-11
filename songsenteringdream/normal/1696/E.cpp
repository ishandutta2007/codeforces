#include<cstdio>
using namespace std;
const int o=4e5+10,MOD=1e9+7;
int n,fac[o],inv[o],ans;
inline int C(int x,int y){if(x<y) return 0;return fac[x]*1ll*inv[y]%MOD*inv[x-y]%MOD;}
int main(){
	scanf("%d",&n);inv[1]=1;
	for(int i=2;i<o;++i) inv[i]=MOD-MOD/i*1ll*inv[MOD%i]%MOD;
	for(int i=fac[0]=inv[0]=1;i<o;++i) fac[i]=fac[i-1]*1ll*i%MOD,inv[i]=inv[i-1]*1ll*inv[i]%MOD;
	for(int i=0,a;i<=n;++i) scanf("%d",&a),ans=(ans+C(i+a,i+1))%MOD;
	printf("%d",ans);
	return 0;
}