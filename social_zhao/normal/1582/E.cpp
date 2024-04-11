#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int f[N][505], a[N], suf[N], n;

void solve() {
	n = get();
	for(int i = 1; i <= n + 3; i++)
		suf[i] = 0, memset(f[i], 0, sizeof(f[i]));
	for(int i = 1; i <= n; i++) a[i] = get(), suf[i] = suf[i - 1] + a[i];
//	memset(f, 0, sizeof(f));
	for(int i = n; i >= 1; i--) {
		for(int j = 1; j <= min(500ll, n - i + 1); j++) {
			if(j == 1) f[i][j] = max(a[i], f[i + 1][1]);
			else if(i + j <= n) {
				f[i][j] = f[i + 1][j];
				if(f[i + j][j - 1] > suf[i + j - 1] - suf[i - 1]) 
					f[i][j] = max(f[i][j], suf[i + j - 1] - suf[i - 1]);
			}
		}
	}
	for(int i = 500; i >= 1; i--) 
		if(f[1][i]) { cout << i << endl; return; }
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
5
1 1 2 2 3
*/