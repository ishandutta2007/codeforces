#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105;
int n, a[N], f[N][N], mex[N][N];
map<int, int> mp;

int GetMex(int l, int r) {
	mp.clear();
	for(int i = l; i <= r; i++) mp[a[i]] = 1;
	int res = 0;
	while(mp[res]) ++res;
	return res;
}

void solve() {
	n = get();
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
			mex[i][j] = GetMex(i, j);
	for(int i = n; i >= 1; i--)
		for(int j = i; j <= n; j++)
			for(int k = i; k <= j; k++)
				f[i][j] = max(f[i][j], f[i][k - 1] + mex[k][j] + 1);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
			ans += f[i][j];
	cout << ans << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}