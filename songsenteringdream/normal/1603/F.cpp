#include<cstdio>
using namespace std;
const int o=1e7+10,MOD=998244353;
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*1ll*b%MOD) if(f&1) res=res*1ll*b%MOD;return res;}
int T,n,k,x,pw[o],pw2[o],ans;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),ans=0){
		scanf("%d%d%d",&n,&k,&x);
		for(int i=pw[0]=1;i<=k;++i) pw[i]=pw[i-1]*2%MOD;
		if(!x){
			if(n<=k){
				ans=1;
				for(int i=0;i<n;++i) ans=ans*1ll*(pw[k]+MOD-pw[i])%MOD;
			}
			continue;
		}
		for(int i=pw2[0]=1,j=qp(2,n);i<=k;++i) pw2[i]=pw2[i-1]*1ll*j%MOD;
		for(int i=0,coef=1;i<k;coef=coef*1ll*(pw[k-(++i)]-1)%MOD)
			ans=(ans+((i&1)?(MOD-1ll):1ll)*pw2[k-i-1]%MOD*coef%MOD*pw[k-i-1])%MOD;
	}
	return 0;
}