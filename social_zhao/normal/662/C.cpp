#include<bits/stdc++.h>
#define rev(x) (((1 << n) - 1) ^ x)
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 21, M = 1e5 + 5, S = 1 << N;
int n, m;
int f[S], g[S], num[M], cnt[S];

void FWT(int *A, int type) {
	for(int mid = 1; mid < 1 << n; mid <<= 1)
		for(int i = 0; i < 1 << n; i += mid << 1)
			for(int j = 0; j < mid; j++) {
				int x = A[i + j], y = A[i + j + mid];
				A[i + j] = (x + y) / type;
				A[i + j + mid] = (x - y) / type;
			}
}

char shit[M];

signed main() {
	n = get(), m = get();
	for(int i = 0; i < n; i++) {
		scanf("%s", shit + 1);
		for(int j = 1; j <= m; j++) num[j] |= (shit[j] - '0') << i;
	}
	for(int i = 0; i < 1 << n; i++) cnt[i] = cnt[i >> 1] + (i & 1);
	for(int i = 1; i <= m; i++) g[num[i]]++;
	for(int i = 0; i < 1 << n; i++) f[i] = min(cnt[i], cnt[rev(i)]);
	FWT(f, 1), FWT(g, 1);
	for(int i = 0; i < 1 << n; i++) f[i] = f[i] * g[i];
	FWT(f, 2);
	int ans = 0x3f3f3f3f;
	for(int i = 0; i < 1 << n; i++) ans = min(ans, f[i]);
	printf("%lld\n", ans);
	return 0;
}