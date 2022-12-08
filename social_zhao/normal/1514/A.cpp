#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
} 

const int N = 1e4 + 5;
int vis[N], n, a[N];

void init() {
	for(int i = 1; i * i < N; i++) vis[i * i] = 1;
}

void solve() {
	n = get();
	int flag = 1;
	for(int i = 1; i <= n; i++) a[i] = get(), flag &= vis[a[i]];
	printf(flag? "NO\n" : "YES\n");
}

int main() {
	init();
	int T = get();
	while(T--) solve();
	return 0;
}