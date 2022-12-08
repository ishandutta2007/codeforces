#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105;
int cnt[N][N][N], f[N][N], n, m;

int main() {
	n = get(), m = get();
	for(int der = 1; der <= n; der++) {
		int k = get();
		for(int ber = 1; ber <= k; ber++) {
			int l = get(), r = get();
			for(int i = 1; i <= l; i++)
				for(int j = r; j <= m; j++)
					for(int k = l; k <= r; k++)
						++cnt[i][j][k];
		}
	}
	for(int i = m; i >= 1; i--)
		for(int j = i; j <= m; j++) {
			f[i][j] = 0;
			for(int k = i; k <= j; k++)
				f[i][j] = max(f[i][j], f[i][k - 1] + f[k + 1][j] + cnt[i][j][k] * cnt[i][j][k]);
		}
	printf("%d\n", f[1][m]);
	return 0;
}