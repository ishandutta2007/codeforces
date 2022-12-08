#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, k, p[N], vis[N];

int main() {
	n = get(), k = get();
	if(k == 0) {
		for(int i = 1; i <= n * 2; i++) printf("%d ", i);
		return 0;
	}
	p[1] = 1 + k, p[2] = 1, vis[1 + k] = vis[1] = 1;
	int now = 1;
	for(int i = 3; i <= n * 2; i++) {
		while(vis[now]) now++;
		p[i] = now;
		now++;
	}
	for(int i = 1; i <= n * 2; i++) printf("%d ", p[i]);
	return 0;
}