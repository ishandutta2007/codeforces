#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1005;
int n, m, col[N];
int mp[N][N];

struct Vector {
	int a[N], len;
	Vector(int x = 0) { memset(a, 0, sizeof(a)), len = x; }
	int& operator[] (int x) { return a[x]; }
	Vector operator +(Vector b) { assert(len == b.len); Vector res(len); for(int i = 1; i <= len; i++) res[i] = (a[i] + b[i]) % 3; return res; }
	Vector operator -(Vector b) { assert(len == b.len); Vector res(len); for(int i = 1; i <= len; i++) res[i] = (a[i] - b[i] + 3) % 3; return res; } 
	Vector operator *(int b) { assert(b); Vector res(len);  for(int i = 1; i <= len; i++) res[i] = a[i] * b % 3; return res; }
};

namespace Equation {
	Vector a[N];
	int sze, vis[N]; 
	
	void clear() {
		for(int i = 1; i <= m; i++) a[i] = Vector(m + 1);
		memset(vis, 0, sizeof(vis)), sze = 0;
	}
	
	void insert(Vector x) { a[++sze] = x; }
	
	int fuck() {
		sze = max(sze, m);
		for(int i = 1; i <= m; i++) {
			int p = i;
			for(int j = 1; j <= sze; j++) if(!vis[j] && a[j][i]) p = j;
			swap(a[i], a[p]);
			if(!a[i][i]) continue;
			a[i] = a[i] * a[i][i], vis[i] = 1;
			for(int j = 1; j <= sze; j++) 
				if(j != i && a[j][i]) a[j] = a[j] - a[i] * a[j][i];
		}
		for(int i = 1; i <= sze; i++) {
			int flag = 1;
			for(int j = 1; j <= m; j++) flag &= !a[i][j];
			if(flag && a[i][m + 1]) return 0;
		}
		return 1;
	}
}

int shit[N];

void solve() {
	n = get(), m = get();
	Equation::clear();
	memset(mp, 0, sizeof(mp));
	int flag = 1;
	for(int i = 1; i <= m; i++) {
		int u = get(), v = get(), w = get();
		mp[u][v] = mp[v][u] = i, col[i] = w;
		if(w != -1) {
			Vector nw = Vector(m + 1);
			nw[i] = 1, nw[m + 1] = w % 3;
			Equation::insert(nw);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			for(int k = j + 1; k <= n; k++) {
				if(mp[i][j] && mp[j][k] && mp[i][k]) {
					Vector nw = Vector(m + 1);
					nw[mp[i][j]] = nw[mp[j][k]] = nw[mp[i][k]] = 1;
					Equation::insert(nw);
				}
			}
		}
	}
	flag = Equation::fuck();
	if(!flag) printf("-1\n");
	else {
		for(int i = 1; i <= m; i++) {
			if(!Equation::a[i][m + 1]) printf("3 ");
			else printf("%d ", Equation::a[i][m + 1]);
		}
		printf("\n");
	}
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}