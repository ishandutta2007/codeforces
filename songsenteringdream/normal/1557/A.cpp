#include<cstdio>
#include<algorithm>
using namespace std;
const int o=1e5+10;
int T,n,a[o];double s;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		s=0;for(int i=1;i<n;++i) s+=a[i];
		printf("%.9lf\n",s/(n-1)+a[n]);
	}
	return 0;
}