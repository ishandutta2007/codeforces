#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, p[N], fa[N];

int find(int x) { return x == fa[x]? x : fa[x] = find(fa[x]); }

int main() {
	n = get();
	if(n & 1) { cout << -1 << endl; return 0; }
	for(int i = 0; i < n; i++) fa[i] = i;
	for(int i = 0; i < n / 2; i++) p[i] = (i * 2) % n;
	for(int i = n / 2; i < n; i++) p[i] = (i * 2 + 1) % n;
	for(int i = 0; i < n; i++) if(find(i) != find(p[i])) fa[find(i)] = find(p[i]);
	for(int i = 0; i < n / 2; i++) 
		if(find(i) != find(i + n / 2)) 
			swap(p[i], p[i + n / 2]), fa[find(i)] = find(i + n / 2);
	cout << 0 << " ";
	int now = p[0];
	while(now != 0) cout << now << " ", now = p[now];
	cout << 0;
	return 0;
}