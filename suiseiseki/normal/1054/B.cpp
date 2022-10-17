#include <cstdio>
int main(){
	int n;
	int a,maxn=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		if(a>maxn){
			printf("%d\n",i);
			return 0;
		}
		if(a==maxn){
			maxn++;
		}
	}
	puts("-1");
	return 0;
}