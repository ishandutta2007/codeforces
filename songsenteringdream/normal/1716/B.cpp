#include<cstdio>
#include<iostream>
using namespace std;
int T,n,a[10000];
inline void prt(){for(int i=1;i<=n;++i) printf("%d ",a[i]);putchar('\n');}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		printf("%d\n",n);
		for(int i=1;i<=n;++i) a[i]=i;
		prt();
		for(int i=2;i<=n;++i) swap(a[1],a[i]),prt();
	}
	return 0;
}