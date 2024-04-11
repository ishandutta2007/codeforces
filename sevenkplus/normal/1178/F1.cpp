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
#define N 510
int m, n;
int a[N];
int b[N][N];
int f[N][N];

int ff(int l, int r) {
	if (f[l][r] != -1) return f[l][r];
	if (l >= r-1) return f[l][r] = 1;

	int S = 0;
	int T = 0;
	int p = b[l][r];
	for (int k = l; k <= p; k ++)
		(S += (ll) ff(l, k) * ff(k, p)%P) %= P;
	for (int k = p+1; k <= r; k ++)
		(T += (ll) ff(p+1, k) * ff(k, r)%P) %= P;

	return f[l][r] = (ll)S*T%P;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		a[i] --;
	}

	for (int i = 0; i < n; i ++) {
		int p = -1;
		for (int j = i; j < n; j ++) {
			if (p == -1 || a[j] < a[p]) p = j;
			b[i][j+1] = p;
		}
	}

	memset(f, -1, sizeof f);
	
	cout << ff(0, n) << endl;
	return 0;
}