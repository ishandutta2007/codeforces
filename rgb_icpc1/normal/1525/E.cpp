#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i ++)
using namespace std;
const int mx = 50005, mn = 25;
const int MOD = 998244353;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;
int d[mn][mx];
int a[mn], id[mn];
int inv[25];

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	inv[1] = 1;
	for (int i = 2; i <= n; i++) inv[i] = 1ll * inv[MOD % i] * (MOD - MOD / i) % MOD;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> d[i][j];
	int f = 1;
	for (int i = 1; i <= n; i++) f = 1ll * f * i % MOD;
	int rlt = 0;
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) a[i] = d[i][j] - 1, id[i] = i;
		sort(id + 1, id + n + 1, [](int i1, int i2) { return a[i1] < a[i2]; } );
		int ans = 1;
		for (int i = 1; i <= n; i++) {
			int c = a[id[i]] - (i - 1);
			if (c <= 0) c = 0;
			ans = 1ll * ans * c % MOD;
		}
		ans = (f - ans + MOD) % MOD;
		rlt = (rlt + ans) % MOD;
	}
	for (int i = 1; i <= n; i++) rlt = 1ll * rlt * inv[i] % MOD;
	cout << rlt << endl;
	
	return 0;
	
}