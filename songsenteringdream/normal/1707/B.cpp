#include<cstdio>
#include<algorithm>
using namespace std;
const int o=1e5+10;
int T,n,m,a[o],b[o],c0;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",n?a[n]:0),c0=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int asd=n;--asd;){
			if(c0) a[0]=a[1];
			for(int i=1;i<n;++i) a[i]=a[i+1]-a[i];
			if(c0) a[n++]=a[0],--c0;
			sort(a+1,a+n);m=0;
			for(int i=1;i<n;++i) if(!a[i]) ++c0;else b[++m]=a[i];
			n=m;
			for(int i=1;i<=n;++i) a[i]=b[i];
		}
	}
	return 0;
}