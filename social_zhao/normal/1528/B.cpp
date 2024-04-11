#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5, P = 998244353;
int n, pri[N], vis[N], tot, d[N], mind[N], f[N], sum[N];

void sprime(int n) {
	d[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) pri[++tot] = i, d[i] = 2, mind[i] = 2;
		for(int j = 1; j <= tot && i * pri[j] <= n; j++) {
			vis[i * pri[j]] = 1;
			if(i % pri[j] == 0) { d[i * pri[j]] = d[i] / mind[i] * (mind[i] + 1), mind[i * pri[j]] = mind[i] + 1; break; }
			d[i * pri[j]] = d[i] * 2, mind[i * pri[j]] = 2;
		}
	}
}

int main() {
	n = get();
	sprime(n);
	f[1] = sum[1] = 1;
	for(int i = 2; i <= n; i++) f[i] = (d[i] + sum[i - 1]) % P, sum[i] = (sum[i - 1] + f[i]) % P;
	printf("%d\n", f[n]);
	return 0;
}