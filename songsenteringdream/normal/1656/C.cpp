#include<cstdio>
#include<algorithm>
using namespace std;
const int o=1e5+10;
int T,n,a[o];
inline void slv(){
	bool flg=1;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),flg&=(a[i]!=1);
	if(flg){printf("YES\n");return;}
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i) if(a[i]+1==a[i+1]){printf("NO\n");return;}
	printf("YES\n");
}
int main(){for(scanf("%d",&T);T--;slv());return 0;}