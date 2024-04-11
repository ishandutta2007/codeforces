#include <cstdio>
typedef long long ll;
int a,b,c,d;
ll calc_1(int n){
	return 1ll*n*a;
}
ll calc_2(int n){
	return 1ll*n*(n-1)/2*d*b;
}
bool check(int n){
	return a>1ll*(n-1)*b*d;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a>1ll*b*c){
			puts("-1");
			continue;
		}
		if(d>c){
			printf("%d\n",a);
			continue;
		}
		int left=1,right=c/d+1;
		while(left<right){
			int mid=(left+right+1)>>1;
			if(check(mid)){
				left=mid;
			}
			else{
				right=mid-1;
			}
		}
		printf("%lld\n",calc_1(left)-calc_2(left));
	}
	return 0;
}