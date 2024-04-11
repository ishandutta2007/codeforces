#include<cstdio>
using namespace std;
int T,n,m;char a[60],b[60];bool flg;
int main(){
	for(scanf("%d",&T);T--;printf(flg?"YES\n":"NO\n"),flg=0){
		scanf("%d%d%s",&n,&m,a+1);scanf("%s",b+n-m+1);
		for(int i=1;i<=n-m+1;++i) flg|=(a[i]==b[n-m+1]);
		for(int i=n-m+2;i<=n;++i) flg&=(a[i]==b[i]);
	}
	return 0;
}