#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e7 + 5, P = 1e9 + 7;
int n, mx, S[N], pw2[N], f[N];
int pri[N / 10], mu[N], vis[N], tot, p[N];

void init(int n) {
	mu[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) pri[++tot] = i, mu[i] = -1;
		for(int j = 1; j <= tot && i * pri[j] <= n; j++) {
			vis[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
			mu[i * pri[j]] = -mu[i];
		}
	}
}

void GetPreSum(int *A) {
	for(int i = 1; i <= tot; i++) 
		for(int j = 1; pri[i] * j <= mx; j++)
			(A[pri[i] * j] += A[j]) %= P;
}

void GetSufSum(int *A) {
	for(int i = 1; i <= tot; i++)
		for(int j = mx / pri[i]; j >= 1; j--)
			(A[j] += A[pri[i] * j]) %= P;
}

void GetSufDelt(int *A) {
	for(int i = 1; i <= tot; i++)
		for(int j = 1; pri[i] * j <= mx; j++)
			(A[j] -= A[pri[i] * j]) %= P;
}

main() {
	n = get();
	for(int i = 1, a; i <= n; i++) a = get(), S[a]++, mx = max(mx, a);
	init(mx);
	pw2[0] = 1;
	GetSufSum(S);
	for(int i = 1; i <= mx; i++) p[i] = mu[i] * S[i];
	GetPreSum(p);
	for(int i = 1; i <= n; i++) pw2[i] = pw2[i - 1] * 2ll % P;
	for(int i = 1; i <= mx; i++) f[i] = pw2[S[i]] - 1;
	GetSufDelt(f);
	int ans = 0;
	for(int i = 2; i <= mx; i++) ans = (ans + 1ll * f[i] * p[i]) % P;
	ans = (ans % P + P) % P;
	cout << ans;
	return 0;
}