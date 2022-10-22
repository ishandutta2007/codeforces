#include<cstdio>
using namespace std;
const int o=5010;
int k,M,C[o][o],s[o][o],pw[o][o],fac[o],ans;
int main(){
	scanf("%d%d",&k,&M);
	for(int i=0;i<=k;++i) for(int j=pw[i][0]=1;j<=k;++j) pw[i][j]=pw[i][j-1]*1ll*i%M;
	for(int i=fac[0]=1;i<=k;++i) fac[i]=fac[i-1]*1ll*i%M;
	for(int i=C[0][0]=1;i<=k;++i) for(int j=C[i][0]=1;j<=i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
	for(int i=s[0][0]=1;i<=k;++i) for(int j=1;j<=i;++j) s[i][j]=(s[i-1][j-1]+s[i-1][j]*(i-1ll+j))%M;
	for(int i=1;i<k;++i) for(int j=0;j<=i;++j)
		ans=(ans+C[k][i]*1ll*C[i][j]%M*s[k-i][i-j]%M*fac[i-j]%M*pw[k-1][i-j]%M*pw[k-i][j])%M;
	printf("%d",ans);
	return 0;
}