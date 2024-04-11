#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 55
ll a[N], s[N];
bool f[N][N];
int n, k;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	for (int i = 0; i < n; i ++)
		s[i+1] = s[i] + a[i];
	ll S = 0;
	for (int p = 60; p >= 0; p--) {
		ll T = S | (1LL<<p);
		memset(f, 0, sizeof f);
		f[0][0] = true;
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < k; j ++) if (f[i][j])
				for (int w = i+1; w <= n; w ++)
					if (((s[w] - s[i])&T) == T) f[w][j+1] = true;
		if (f[n][k]) S = T;
	}
	cout << S << endl;
	return 0;
}