#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

const int N = 1e5 + 10;
int n, c[N], deg[N], u[N], v[N], high;  

int main() {
	n = rd();	
	for (int i = 1; i < n; i ++) u[i] = rd(), v[i] = rd();
	for (int i = 1; i <= n; i ++) c[i] = rd();
	for (int i = 1; i < n; i ++) {
		if (c[u[i]] != c[v[i]]) {
			deg[u[i]] ++, deg[v[i]] ++;
			high ++;
		}
	}
	for (int i = 1; i <= n; i ++) if (deg[i] == high) return printf("YES\n%d", i), 0;
	return puts("NO"), 0;
}