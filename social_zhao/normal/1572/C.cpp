#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e3 + 5;
int n, a[N], f[N][N];
vector<int> pos[N];

void clear(int n) {
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			f[i][j] = 0;
	for(int i = 1; i <= n; i++) pos[i].clear(); 
}

void solve() {
	n = get();
	clear(n);
	for(int i = 1; i <= n; i++) a[i] = get(), pos[a[i]].push_back(i);
	for(int i = n; i >= 1; i--)
		for(int j = i + 1; j <= n; j++) {
			f[i][j] = f[i + 1][j];
			for(int t = 0; t < pos[a[i]].size(); ++t) {
				int k = pos[a[i]][t];
				if(i < k && k <= j) f[i][j] = max(f[i][j], 1 + f[i + 1][k - 1] + f[k][j]);
			}
		}
	printf("%d\n", n - 1 - f[1][n]);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}