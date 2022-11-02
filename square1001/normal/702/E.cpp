#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, f[39][100009], t[39][100009]; ll m, w[39][100009];
int main() {
	scanf("%d%lld", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", &f[0][i]);
	for(int i = 0; i < n; i++) scanf("%d", &w[0][i]), t[0][i] = w[0][i];
	for(int i = 0; i < 34; i++) {
		for(int j = 0; j < n; j++) {
			f[i + 1][j] = f[i][f[i][j]];
			w[i + 1][j] = w[i][j] + w[i][f[i][j]];
			t[i + 1][j] = min(t[i][j], t[i][f[i][j]]);
		}
	}
	for(int i = 0; i < n; i++) {
		int pos = i, r2 = 999999999; ll r1 = 0;
		for(int j = 0; j < 34; j++) {
			if(m & (1LL << j)) {
				r1 += w[j][pos];
				r2 = min(r2, t[j][pos]);
				pos = f[j][pos];
			}
		}
		printf("%lld %d\n", r1, r2);
	}
	return 0;
}