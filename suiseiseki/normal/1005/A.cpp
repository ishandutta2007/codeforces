#include <cstdio>
int a[1005];
int x[1005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int len=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]+1){
			x[++len]=a[i-1];
		}
	}
	x[++len]=a[n];
	printf("%d\n",len);
	for(int i=1;i<=len;i++){
		printf("%d ",x[i]);
	}
	puts("");
	return 0;
}