#include <cstdio>
#define Maxn 100
int a[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n;i++){
		if((a[i]==2&&a[i-1]==3)||(a[i]==3&&a[i-1]==2)){
			puts("Infinite");
			return 0;
		}
	}
	int ans=0;
	for(int i=2;i<=n;i++){
		if(a[i-2]==3&&a[i-1]==1&&a[i]==2){
			ans--;
		}
		if(a[i-1]==1&&a[i]==2){
			ans+=3;
		}
		if(a[i-1]==1&&a[i]==3){
			ans+=4;
		}
		if(a[i-1]==2&&a[i]==1){
			ans+=3;
		}
		if(a[i-1]==3&&a[i]==1){
			ans+=4;
		}
	}
	puts("Finite");
	printf("%d\n",ans);
	return 0;
}
//////////////