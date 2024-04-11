#include <cstdio>
#define Maxn 1000
int x[Maxn+5],y[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	x[1]=1,y[1]=1;
	for(int i=2;i<=n;i++){
		if(x[i-1]+1<=y[i-1]){
			x[i]=x[i-1]+1;
			y[i]=y[i-1];
		}
		else{
			x[i]=x[i-1];
			y[i]=y[i-1]+1;
		}
	}
	printf("%d\n",mx(x[n],y[n]));
	for(int i=1;i<=n;i++){
		printf("%d %d\n",x[i],y[i]);
	}
	return 0;
}