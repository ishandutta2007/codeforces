#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, k, phi[N], pri[N], vis[N], tot;

void init(int n) {
	phi[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) pri[++tot] = i, phi[i] = i - 1;
		for(int j = 1; j <= tot && i * pri[j] <= n; j++) {
			vis[i * pri[j]] = 1;
			if(i % pri[j] == 0) { phi[i * pri[j]] = phi[i] * pri[j]; break; }
			phi[i * pri[j]] = phi[i] * (pri[j] - 1); 
		}
	}
	sort(phi + 3, phi + n + 1);
}

main() {
	n = get(), k = get();
	init(n);
	if(k == 1) return printf("3\n"), 0;
	int ans = 0;
	for(int i = 1; i <= k; i++) ans += phi[i + 2];
	printf("%lld\n", ans + 2);
	return 0;
}