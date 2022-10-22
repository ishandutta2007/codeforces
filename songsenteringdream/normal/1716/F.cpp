#include<cstdio>
using namespace std;
const int o=2010,MOD=998244353;
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*1ll*b%MOD) if(f&1) res=res*1ll*b%MOD;return res;}
int T,n,m,k,ans,s[o][o],q;
int main(){
	for(int i=s[0][0]=1;i<o;++i) for(int j=1;j<=i;++j) s[i][j]=(s[i-1][j-1]+s[i-1][j]*1ll*j)%MOD;
	for(scanf("%d",&T);T--;printf("%d\n",ans),ans=0){
		scanf("%d%d%d",&n,&m,&k);
		if(m==1){ans=qp(n,k);continue;}
		q=(m+1ll)/2*qp(m/2,MOD-2)%MOD;
		for(int i=1,coef=qp(q+1,n),inv=qp(q+1,MOD-2);i<=k;++i)
			coef=coef*(n-i+1ll)%MOD*q%MOD*inv%MOD,ans=(ans+s[k][i]*1ll*coef)%MOD;
		ans=ans*1ll*qp(m/2,n)%MOD;
	}
	return 0;
}