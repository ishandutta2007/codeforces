#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int P = 998244353;
const int N = 2e6 + 10;
long long n, factor[N], ans[N], a[N];


int main() {
	n = rd();
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= n; j += i) 
			factor[j] ++; 
	}
	ans[1] = a[1] = 1;
	for (int i = 2; i <= n; i ++) {
		a[i] = (ans[i - 1] + factor[i]) % P;
		ans[i] = (ans[i -1] + a[i]) % P;
	} 
	printf("%lld\n", a[n]); 
	return 0;
}