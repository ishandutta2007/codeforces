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

#define N 4010
int n;
int a[N];
bitset<N> v[N];

int main() {
	int _;
	cin >> _;
	// _=1;
	while (_--) {
		// n = 1000;
		// for (int i = 0; i < n*2; i ++) a[i] = i;
		cin >> n;
		for (int i = 0; i < n*2; i ++) cin >> a[i];
		for (int i = 0; i <= n*2; i ++)
			v[i].reset();
		
		for (int i = n*2-1; i >= n; i--) v[i][0] = true;
		for (int i = n*2-1; i >= 1; i--) {
			bitset<N> w;
			w.reset();
			for (int j = 0; j <= n; j ++) if (v[i][j])
				w[n*2-i-j] = true;
			for (int k = i-1; k >= 0 && a[k] < a[i] && i-k <= n; k--)
				v[k] |= w;
		}
				
		puts (v[0][n]?"YES":"NO");
	}
	return 0;
}