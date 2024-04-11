#include <bits/stdc++.h>

int main(){
	int cas;
	scanf("%d", &cas);
	while (cas--){
		int n;
		scanf("%d", &n);
		long long ans = n * (long long)(n + 1) / 2;
		for (int i = 31 - __builtin_clz(n); i >= 0; --i)
			ans -= 1ll << i + 1;
		printf("%I64d\n", ans);
	}
	return 0;
}