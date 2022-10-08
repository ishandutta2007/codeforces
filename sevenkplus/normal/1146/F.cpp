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

#define P 998244353
#define N 200010

int n; vector<int> A[N];
int f[N], g[N];

int mpow(int x, int y) {
	int s = 1, t = x;
	while (y) {
		if (y&1) s = (ll)s*t%P;
		t = (ll)t*t%P;
		y /= 2;
	}
	return s;
}

int inv(int x) {
	return mpow(x, P-2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i ++) {
		int x; cin >> x; A[x-1].pb(i);
	}
	for (int i = n-1; i >= 0; i--) {
		if (A[i].empty()) {
			f[i] = g[i] = 1;
			continue;
		}
		int u = 1, h = 1;
		for (auto p : A[i]) {
			u = (ll)u * (f[p] + g[p])%P;
			h = (ll)h * f[p]%P;
		}
		g[i] = (u-h+P)%P;
		int c = 0;
		for (auto p : A[i])
			(c += (ll)h*inv(f[p])%P*g[p]%P) %= P;
		f[i] = (u-c+P)%P;
	}
	printf("%d\n", f[0]);
	return 0;
}