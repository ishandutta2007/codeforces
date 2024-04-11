#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d %d\n",x-1,y);
	}
	return 0;
}