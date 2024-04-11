#include <cstdio>
typedef long long ll;
const int Maxn=50;
int n;
int a[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ll sum_0=0,sum_1=0,all_sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			all_sum+=a[i];
			if(i&1){
				sum_1+=a[i];
			}
			else{
				sum_0+=a[i];
			}
		}
		if((sum_0<<1)<=all_sum){
			for(int i=1;i<=n;i++){
				if(i&1){
					printf("%d ",a[i]);
				}
				else{
					printf("%d ",1);
				}
			}
			puts("");
		}
		else if((sum_1<<1)<=all_sum){
			for(int i=1;i<=n;i++){
				if(i&1){
					printf("%d ",1);
				}
				else{
					printf("%d ",a[i]);
				}
			}
			puts("");
		}
		else{
			break;
		}
	}
	return 0;
}