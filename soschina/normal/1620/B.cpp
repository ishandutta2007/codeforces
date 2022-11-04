#include <cstdio>
#include <iostream>
using namespace std;

int t, n, m, k, a, b;
long long ans;

int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < 2; i++){
			scanf("%d%d", &k, &a);
			k--;
			while(k--)
				scanf("%d", &b);
			ans = max(ans, 1ll * (b - a) * m);
		}
		for(int i = 0; i < 2; i++){
			scanf("%d%d", &k, &a);
			k--;
			while(k--)
				scanf("%d", &b);
			ans = max(ans, 1ll * (b - a) * n);
		}
		printf("%lld\n", ans);
	}
	return 0;
}