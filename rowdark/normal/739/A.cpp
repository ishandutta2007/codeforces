#include<stdio.h>
#include<algorithm>
int n,m,md;
int main(){
	scanf("%d%d",&n,&m);
	md=n;
	for(int i=0;i<m;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		md=std::min(md,b-a+1);
	}
	printf("%d\n",md);
	for(int i=0;i<n;++i) printf("%d%c",i%md,i==n-1?'\n':' ');
	return 0;
}