#include <cstdio>
#define Maxn 100000
int n,x,y;
int a[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	bool yes=0;
	for(int i=1;i<=n;i++){
		yes=1;
		for(int j=mx(1,i-x);j<=mn(n,i+y);j++){
			if(a[j]<a[i]){
				yes=0;
			}
		}
		if(yes){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}