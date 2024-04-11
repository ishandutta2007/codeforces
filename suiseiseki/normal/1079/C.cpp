#include <cstdio>
#define Maxn 100000
int a[Maxn+5];
int b[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(a[1]==a[2]){
		b[1]=3;
	}
	else if(a[1]>a[2]){
		b[1]=5;
	}
	else{
		b[1]=1;
	}
	for(int i=2;i<=n;i++){
		if(a[i-1]<a[i]){
			if(a[i]<=a[i+1]){
				b[i]=b[i-1]+1;
			}
			else{
				b[i]=mx(b[i-1]+1,5);
			}
		}
		else if(a[i-1]>a[i]){
			if(a[i]>=a[i+1]){
				b[i]=b[i-1]-1;
			}
			else{
				b[i]=mn(b[i-1]-1,1);
			}
		}
		else{
			if(a[i]<a[i+1]){
				if(b[i-1]==1){
					b[i]=2;
				}
				else{
					b[i]=1;
				}
			}
			else if(a[i]>a[i+1]){
				if(b[i-1]==5){
					b[i]=4;
				}
				else{
					b[i]=5;
				}
			}
			else{
				if(b[i-1]==3){
					b[i]=2;
				}
				else{
					b[i]=3;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]<1||b[i]>5){
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",b[i]);
	}
	puts("");
	return 0;
}