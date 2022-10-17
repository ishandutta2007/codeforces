#include <cstdio>
typedef long long ll;
const int Maxn=100000;
int n;
int a[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ll sum=0;
		int maxn=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
			if(a[i]>maxn){
				maxn=a[i];
			}
		}
		if(1ll*maxn*(n-1)-sum>=0){
			printf("%lld\n",1ll*maxn*(n-1)-sum);
		}
		else{
			if(sum%(n-1)==0){
				puts("0");
			}
			else{
				printf("%lld\n",sum/(n-1)*(n-1)+(n-1)-sum);
			}
		}
	}
	return 0;
}