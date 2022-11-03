#include <bits/stdc++.h>

int main(){
	int n, k, s = 1;
	scanf("%d%d", &n, &k);
	for (int i = n - 1; i >= 0; --i){
		scanf("%d", &n);
		int d = std::__gcd(n, k);
		s = s / std::__gcd(d, s) * d;
	}
	puts(s == k ? "Yes" : "No");
	return 0;
}