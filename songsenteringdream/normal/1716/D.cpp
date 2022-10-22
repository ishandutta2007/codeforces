#include<cstdio>
using namespace std;
const int o=2e5+10,MOD=998244353;
int n,k,f[o],g[o],ans[o];
int main(){
	scanf("%d%d",&n,&k);
	for(bool flg=f[0]=1;flg;++k){
		for(int i=0;i<=n;++i) g[i]=0;
		for(int i=k;i<=n;++i) g[i]=(f[i-k]+g[i-k])%MOD;
		flg=0;
		for(int i=0;i<=n;++i) flg|=!!(f[i]=g[i]),ans[i]=(ans[i]+g[i])%MOD;
	}
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	return 0;
}