#include<cstdio>
using namespace std;
int n,k;
int main(){
	scanf("%d",&n);
	for(;3*k+1<2*n;++k);
	printf("%d\n",k);
	if(n<2){printf("1 1\n");return 0;}
	for(;n%3!=2;--n) printf("%d %d\n",n,n);
	for(int i=1,j=n/3;j;printf("%d %d\n",i++,j--));
	for(int i=n-n/3,j=n;i<=n;printf("%d %d\n",i++,j--));
	return 0;
}