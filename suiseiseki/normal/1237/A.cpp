#include <cstdio>
#define Maxn 13845
int a[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i]/2;
	}
	for(int i=1;i<=n;i++){
		if(a[i]%2==0){
			printf("%d\n",a[i]/2);
		}
		else{
			if(a[i]<0){
				if(sum>0){
					sum--;
					printf("%d\n",a[i]/2-1);
				}
				else{
					printf("%d\n",a[i]/2);
				}
			}
			else{
				if(sum<0){
					sum++;
					printf("%d\n",a[i]/2+1);
				}
				else{
					printf("%d\n",a[i]/2);
				}
			}
		}
	}
	return 0;
}