#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int n;LL a[N];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n==1) {
		printf("1 1\n");
		printf("%lld\n", -a[1]);
		printf("1 1\n0\n");
		printf("1 1\n0\n");
		return 0;
	}
	printf("1 %d\n", n);
	for(int i=1;i<=n;i++){
		if(i==1)printf("0 ");
		else{
			int tmp=(-a[i]%(n-1)+(n-1))%(n-1);
			a[i] += 1LL*tmp*n;
			printf("%lld ", 1LL*tmp*n);
		}
	}
	printf("\n");

	printf("1 1\n");
	printf("%lld\n", -a[1]);

	printf("2 %d\n", n);
	for (int i = 2; i <= n; i ++) {
		printf("%lld ", -a[i]);
	}
	printf("\n");
}