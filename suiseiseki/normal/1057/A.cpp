#include <cstdio>
int father[200005];
void work(int x){
	if(x==1){
		printf("%d ",x);
		return;
	}
	work(father[x]);
	printf("%d ",x);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d",&father[i]);
	}
	work(n);
	puts("");
	return 0;
}