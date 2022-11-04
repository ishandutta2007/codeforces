#include <cstdio>
#include <iostream>
using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int t, m, d, w, u, s, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &m, &d, &w);
		u = min(m, d);
		if(d == 1){
			printf("%lld\n", 1ll * u * (u - 1) / 2);
			continue;
		}
		s = w / gcd(d - 1, w);
		k = u / s;
		printf("%lld\n", 1ll * k * u - 1ll * k * (1 + k) / 2 * s);
	}
	return 0;
}