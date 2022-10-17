#include <cstdio>
#define Maxn 50000
int a[Maxn<<1|5];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		a[(i<<2)-3]=(i<<2)-3;
		a[(i<<2)-2]=(i<<2)-2;
		a[(i<<2)-1]=(i<<2);
		a[i<<2]=(i<<2)-1;
	}
	for(int i=(k<<2)+1;i<=(n<<1);i+=2){
		a[i]=i+1;
		a[i+1]=i;
	}
	for(int i=1;i<=(n<<1);i++){
		printf("%d ",a[i]);
	}
	puts("");
	return 0;
}