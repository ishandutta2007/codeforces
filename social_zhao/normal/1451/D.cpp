#include<stdio.h>
#include<cmath>
#define int long long

signed main() {
	int T, d, k;
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld%lld", &d, &k);
		int x = sqrt(2) / 2.0 * d / k, _x = x * k, _y = x * k + k;
		if(_x * _x + _y * _y > d * d) printf("Utkarsh\n");
		else printf("Ashish\n");
	}
	return 0;
}