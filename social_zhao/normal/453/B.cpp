#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105, M = 1 << 17;
const int pri[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int n, a[N], f[N][M], g[N], pre[N][M], b[N];

int main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i < 59; i++)
		for(int j = 0; j < 16; j++) 
			if(i % pri[j] == 0) g[i] |= 1 << j;
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= n; i++) 
		for(int S = 0; S < 1 << 16; S++)
			for(int k = 1; k < 59; k++)
				if((g[k] & S) != g[k]) continue;
				else if(f[i - 1][S ^ g[k]] + abs(k - a[i]) <= f[i][S])
					f[i][S] = f[i - 1][S ^ g[k]] + abs(k - a[i]), pre[i][S] = k;
	int pos = 0;
	for(int i = 1; i < 1 << 16; i++) if(f[n][pos] > f[n][i]) pos = i;
	for(int i = n; i > 0; i--) b[i] = pre[i][pos], pos = pos ^ g[pre[i][pos]];
	for(int i = 1; i <= n; i++) printf("%d ", b[i]);
	return 0;
}