#include <cstdio>
int a[10000005];
int main(){
	long long n;
	int k;
	scanf("%I64d",&n);
	scanf("%d",&k);
	int len=0;
	for(int i=1;(long long)i*i<=n;i++){
		if(n%i==0){
			a[++len]=i;
			k--;
			if(k==0){
				printf("%d\n",i);
				return 0;
			}
		}
	}
	if((long long)a[len]*a[len]==n){
		len--;
	}
	for(int i=len;i>0;i--){
		k--;
		if(k==0){
			printf("%I64d\n",n/a[i]);
			return 0;
		}
	}
	puts("-1");
	return 0;
}