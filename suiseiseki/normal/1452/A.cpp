#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=10000;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x,y;
		scanf("%d%d",&x,&y);
		int tmp=min(x,y);
		x-=tmp;
		y-=tmp;
		int ans=(tmp<<1)+(x<<1)+(y<<1);
		if(max(x,y)>0){
			ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}