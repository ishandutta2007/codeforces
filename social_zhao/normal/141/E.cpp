#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, m, _x[N], _y[N], _c[N], vis[N];
int fa[N], cnt;

void clear() { for(int i = 1; i <= n; i++) fa[i] = i; cnt = 0; }
int find(int x) { return x == fa[x]? x : fa[x] = find(fa[x]); }

void GetTree(int col, int lim) {
	for(int i = 1; i <= m; i++) {
		int x = find(_x[i]), y = find(_y[i]);
		if(x == y || _c[i] != col || cnt == lim) continue;
		if(x != y) ++cnt, fa[y] = x, vis[i] = 1;
	}
} 

int main() {
	n = get(), m = get();
	if(n % 2 != 1) return cout << -1 << endl, 0;
	for(int i = 1; i <= m; i++) {
		char c;
		_x[i] = get(), _y[i] = get(), scanf("%s", &c), _c[i] = c == 'S';
	}
	
	clear();
	GetTree(0, n);
	if(cnt < (n - 1) / 2) return cout << -1 << endl, 0;
	GetTree(1, n - 1);
	if(cnt < n - 1) return cout << -1 << endl, 0;
	clear();
	for(int i = 1; i <= m; i++) if(_c[i] == 0) vis[i] = 0;
	for(int i = 1; i <= m; i++) {
		int x = find(_x[i]), y = find(_y[i]);
		if(!vis[i]) continue;
		if(x != y) ++cnt, fa[y] = x;
	} 
	GetTree(1, (n - 1) / 2);
	if(cnt != (n - 1) / 2) return cout << -1 << endl, 0;
	GetTree(0, n);
	
	cout << n - 1 << endl;
	for(int i = 1; i <= m; i++) if(vis[i]) cout << i << " ";
	return 0;
}