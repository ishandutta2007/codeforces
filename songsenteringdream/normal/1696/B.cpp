#include<cstdio>
using namespace std;
const int o=1e5+10;
int T,n,a[o],ans;bool flg;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),ans=0){
		scanf("%d",&n);
		for(int i=flg=1;i<=n;++i) scanf("%d",&a[i]),flg&=!a[i];
		if(flg) continue;
		for(int i=1,j;i<=n;++i) if(a[i]){
			for(j=i;j<=n&&a[j];++j);
			for(flg=1;j<=n;++j) flg&=!a[j];
			ans=2-flg;
			break;
		}
	}
	return 0;
}