#include<cstdio>
#include<algorithm>
using namespace std;
const int o=2e5+10;
int T,n,a[o];long long s,ans,sm;
int main(){
	for(scanf("%d",&T);T--;s=sm=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=2;i<=n;++i) s+=a[1]+a[i];
		if(s>0){printf("INF\n");continue;}
		s=0;
		for(int i=1;i<n;++i) s+=a[i]+a[n];
		if(s<0){printf("INF\n");continue;}
		for(int i=1;i<n;++i) sm+=a[i]*1ll*a[n];
		ans=sm-s*a[n-1];
		for(int i=n-1;i>1;ans=max(ans,sm-s*a[--i]))
			s-=a[i]+a[n],s+=a[i]+a[1],sm-=a[i]*1ll*a[n],sm+=a[i]*1ll*a[1];
		printf("%lld\n",ans);
	}
	return 0;
}