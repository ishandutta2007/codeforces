#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, a[N], sum[N], bin[N << 1], top;

signed main() {
	n = get();
	for(int i = 1; i <= n / 2; i++) a[i] = get();
	for(int i = 1; i <= n / 2; i++) {
		int ansA = 0, ansB = 0x3f3f3f3f;
		for(int j = 1; j * j <= a[i]; j++) {
			if(a[i] % j == 0) {
				int k = a[i] / j;
				if(((k + j) & 1) != 0) continue;
				int A = (k - j) / 2, B = (k + j) / 2;
				if(A * A > sum[i - 1] && B < ansB) ansA = A, ansB = B;
			}
		}
		if(!ansA) { printf("No\n"); return 0; }
		bin[++top] = ansA * ansA - sum[i - 1], bin[++top] = a[i], sum[i] = ansB * ansB;
//		printf("%lld %lld ", bin[top - 1], bin[top]);
	}
	printf("Yes\n");
	for(int i = 1; i <= n; i++) printf("%lld ", bin[i]);
	return 0;
}