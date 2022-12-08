#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5, P = 1e9 + 7;
int n, k;
int pri[N], tot, vis[N], mu[N], pw[N], sum[N];
vector<int> di[N];

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void inc(int &x, int y) { x = (x + y) % P; }

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
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j += i)
			di[j].emplace_back(i);
	pw[0] = 1;
	for(int i = 1; i <= n; i++) pw[i] = pw[i - 1] * k % P;
}

int S(int n) { return (n * (n + 1) / 2) % P; }
int F(int x, int y) { // [i, j <= x && i + j <= y]
	if(y <= x + 1) return S(y - 1);
	else if(y >= x + x) return x * x % P;
	else return (x * x - S(x + x - y) + P) % P;
}
int G(int l, int T, int r) {
	l = (l + T - 1) / T, r = r / T;
	if(l > r) return 0;
	return (r - l + 1);
}

void push(int i) {
	for(int j = i; j <= n; j += i)
		sum[j] += mu[j / i];
}

main() {
	n = get(), k = get();
	init(200000);
	int der1 = 0, der2 = 0, ber = qpow(qpow(k, n), P - 2);
	
	// Part I
	for(int T = 1; T <= n - 1; T++) {
		for(auto d : di[T]) {
			inc(der1, pw[d] * mu[T / d] * F((n - 1) / T, (n + d) / T));
		}
	}
	
	// Part II
	for(int s = n; s <= 2 * n - 2; s++) {
		for(auto T : di[s]) {
			inc(der2, pw[s] * G(s - n + 1, T, n - 1) % P * sum[T]);
		}
		if(s - n > 0) push(s - n);
	}
	der2 = der2 * ber % P;
	
//	cerr << der1 << " " << der2 << endl;
	int ans = (der1 + der2) * ber % P;
	ans = (ans % P + P) % P;
	cout << ans << endl;
	return 0;
}