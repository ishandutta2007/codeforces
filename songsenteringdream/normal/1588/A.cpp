#include<cstdio>
#include<algorithm>
using namespace std;
const int o=110;
int T,n,a[o],b[o];
inline void slv(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	for(int i=1;i<=n;++i) if(a[i]-b[i]&&a[i]+1-b[i]){printf("NO\n");return;}
	printf("YES\n");
}
int main(){
	for(scanf("%d",&T);T--;slv());
	return 0;
}