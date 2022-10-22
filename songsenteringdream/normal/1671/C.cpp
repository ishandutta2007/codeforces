#include<cstdio>
#include<algorithm>
using namespace std;
const int o=2e5+10;
int T,n,x;long long a[o],ans;
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=0){
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i) a[i]+=a[i-1];
		for(int i=1;i<=n;++i) if(a[i]<=x) ans+=(x-a[i])/i+1;
	}
	return 0;
}