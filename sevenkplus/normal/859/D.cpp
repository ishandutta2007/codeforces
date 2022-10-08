#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef long double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 110

int n0, n;
db a[N][N];
db f[9][N];
db g[9][N];

int main() {
	cin >> n0;
	n = (1<<n0);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++) {
			int x;
			cin >> x;
			a[i][j] = x/100.0;
		}
	for (int i = 0; i < n; i ++) f[0][i] = 1.0;
	for (int z = 1; z <= n0; z ++) { // round
		int pz1 = (1<<z-1);
		for (int i = 0; i < n/pz1; i ++) { // winner of 2^(z-1) i ~ 2^(z-1) (i+1)
			int i1 = i^1;
			for (int j = 0; j < pz1; j ++)
				for (int k = 0; k < pz1; k ++) {
					int x = i*pz1+j;
					int y = i1*pz1+k;
					f[z][x] += f[z-1][x]*f[z-1][y]*a[x][y];
				}
		}
	}
	
	/*
	for (int z = 1; z <= n0; z ++)
		for (int i = 0; i < n; i ++)
			printf ("%.9Lf%c", f[z][i], i == n-1?'\n':' ');
	*/
	
	// calculate g
	for (int z = 1; z <= n0; z ++) { // round
		int pz = (1<<z);
		for (int i = 0; i < n/pz; i ++) { // region
			for (int j = 0; j < pz; j ++) { // winner
				int x = i*pz+j;
				db S = 0;
				for (int zz = 1; zz <= z; zz ++) {
					S += (1<<zz-1)*f[zz][x];
				}
				for (int zz = 1; zz < z; zz ++) {
					S += g[zz][(x/(1<<zz))^1];
				}
				g[z][i] = max(g[z][i], S);
			}
		}
	}
	printf ("%.12Lf\n", g[n0][0]);
	return 0;
}