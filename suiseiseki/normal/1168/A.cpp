#include <cstdio>
#define Maxn 300000
int n,m;
int a[Maxn+5];
int b[Maxn+5];
int mn(int a,int b){
	return a<b?a:b;
}
bool check(int x){
	b[n+1]=m;
	for(int i=n;i>0;i--){
		if(a[i]+x>=m){
			if(b[i+1]>=a[i]){
				b[i]=mn(b[i+1],m-1);
			}
			else{
				if((a[i]+x)%m>=b[i+1]){
					b[i]=b[i+1];
				}
				else{
					b[i]=(a[i]+x)%m;
				}
			}
		}
		else{
			if(b[i+1]>=a[i]){
				b[i]=mn(b[i+1],a[i]+x);
			}
			else{
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int left=0,right=m,mid;
	while(left<right){
		mid=(left+right)>>1;
		if(check(mid)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	printf("%d\n",left);
	return 0;
}