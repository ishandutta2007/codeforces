#include<cstdio>
using namespace std;
int T,n,k;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&k);
		if(k>(n+1)/2){printf("-1\n");continue;}
		for(int i=1;i<=n;++i,putchar('\n')) for(int j=1;j<=n;++j)
			putchar((i==j&&i%2&&(i+1)/2<=k)?'R':'.');
	}
	return 0;
}