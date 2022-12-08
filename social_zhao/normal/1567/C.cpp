#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int n, dig[50], len, cnt[50];
int f[50][2][2]; //  i  j k

void solve() {
	n = get();
	len = 0;
	memset(dig, 0, sizeof(dig));
	while(n) dig[++len] = n % 10, n /= 10;
	memset(f, 0, sizeof(f));
	f[0][0][0] = 1;
	for(int i = 0; i < 10; i++)
		for(int j = 0; j <= 1; j++)
			for(int k = 0; k <= 1; k++) {
				if(!f[i][j][k]) continue;
				int now = dig[i + 1] - k;
				if(now >= 0) 
					f[i + 1][now / 10][j] += f[i][j][k] * cnt[now],
					f[i + 1][(now + 10) / 10][j] += f[i][j][k] * cnt[now + 10]; 
				else f[i + 1][(now + 10) / 10 + 1][j] += f[i][j][k] * cnt[now + 10];
			}
	printf("%lld\n", f[10][0][0] - 2);
}

signed main() {
	for(int i = 0; i <= 9; i++)
		for(int j = 0; j <= 9; j++)
			++cnt[i + j];
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
2021
*/