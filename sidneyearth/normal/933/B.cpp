#include <stdio.h>
typedef long long ll;
const int maxn = 1000100;
int a[maxn + 100];
int main(){
	ll p; int k;
	scanf("%I64d%d", &p, &k);
	int d = 0;
	while(p < 0 || p >= k){
		a[d] = (p % k + k) % k;
		p = (a[d] - p) / k;
		d++;
		if(d > maxn) break;
	}
	if(d > maxn)
		printf("-1\n");
	else{
		printf("%d\n", d + 1);
		for(int i = 0; i < d; i++)
			printf("%d ", a[i]);
		printf("%d\n", p);
	}
	return 0;
}