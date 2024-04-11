#include <cstdio>
#define Maxn 300000
int a[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	int zero=0,one=0,two=0;
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
		if(a[i]==0){
			zero++;
		}
		else if(a[i]==1){
			one++;
		}
		else{
			two++;
		}
	}
	if(zero<(n/3)){
		for(int i=1;i<=n&&zero<(n/3);i++){
			if(a[i]==1&&one>(n/3)){
				zero++;
				a[i]=0;
				one--;
			}
			else if(a[i]==2&&two>(n/3)){
				zero++;
				a[i]=0;
				two--;
			}
		}
	}
	else if(zero>(n/3)){
		for(int i=n;i>0&&zero>(n/3);i--){
			if(a[i]==0){
				if(two<(n/3)){
					two++;
					a[i]=2;
					zero--;
				}
				else if(one<(n/3)){
					one++;
					a[i]=1;
					zero--;
				}
			}
		}
	}
	if(one<(n/3)){
		for(int i=1;i<=n&&one<(n/3);i++){
			if(a[i]==2){
				one++;
				two--;
				a[i]=1;
			}
		}
	}
	else if(one>(n/3)){
		for(int i=n;i>0&&one>(n/3);i--){
			if(a[i]==1){
				one--;
				two++;
				a[i]=2;
			}
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d",a[i]);
	}
	puts("");
	return 0;
}