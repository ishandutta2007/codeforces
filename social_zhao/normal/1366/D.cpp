#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e7 + 5, Q = 5e5 + 5;
int n; 
int pri[N], mx[N], vis[N], tot, d1[N], d2[N];

int main() {
	n = get();
	for(int i = 2; i <= 1e7; i++) {
		if(!vis[i]) pri[++tot] = i, mx[i] = i;
		for(int j = 1; j <= tot && i * pri[j] <= 1e7; j++) {
			vis[i * pri[j]] = 1, mx[i * pri[j]] = max(mx[i], pri[j]);
			if(!(i % pri[j])) break;
		}
	}
	for(int i = 1; i <= n; i++) {
		int x = get(), tmp = mx[x], res = 1;
		while(!(x % tmp)) x /= tmp, res *= tmp;
		if(x == 1) d1[i] = d2[i] = -1;
		else d1[i] = res, d2[i] = x;
	}
	for(int i = 1; i <= n; i++) printf("%d ", d1[i]); printf("\n");
	for(int j = 1; j <= n; j++) printf("%d ", d2[j]);
	return 0;
}