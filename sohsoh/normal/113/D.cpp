#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 484 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ld G[MAXN][MAXN], P[MAXN][MAXN], A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN], TB[MAXN], ans[MAXN];
int n, m, a, b, ind[MAXN][MAXN], deg[MAXN];
pair<int, int> ind_r[MAXN];
bool M[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> a >> b;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			ind[i][j] = (i - 1) * n + j, ind_r[(i - 1) * n + j] = {i, j};
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		M[u][v] = M[v][u] = true;
		deg[u]++;
		deg[v]++;
	}
	
	for (int i = 1; i <= n; i++) cin >> C[i], M[i][i] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int x = 1; x <= n; x++) {
				for (int y = 1; y <= n; y++) {
					if (i == j) continue;
					ld p = 1;
					p *= M[i][x];
					p *= M[j][y];
					if (i == x) p *= C[i];
					else p *= (1 - C[i]) / deg[i];
					if (j == y) p *= C[j];
					else p *= (1 - C[j]) / deg[j];
					
					P[ind[i][j]][ind[x][y]] = p;
				}
			}
		}
	}

	int n2 = n * n;
	for (int i = 1; i <= n2; i++) {
		if (ind_r[i].X == ind_r[i].Y) A[i][i] = 1;
		else {
			for (int j = 1; j <= n2; j++) A[i][j] = P[i][j];
			A[i][i] -= 1;
		}
	}


	for (int i = 1; i <= n2; i++) {
		for (int j = 1; j < i; j++) {
			if (A[i][j] != 0) {
				ld x = A[i][j] / A[j][j];
				for (int k = 1; k <= n2; k++) A[i][k] -= x * A[j][k];
				B[i][j] -= x;
			}
		}
	}

	cout << setprecision(10) << fixed;
	for (int i = 1; i <= n; i++) {
		fill(TB, TB + MAXN, 0);
		TB[ind[i][i]] = 1;
		for (int j = 1; j <= n2; j++) {
			for (int k = 1; k <= n2; k++) {	
				TB[j] += TB[k] * B[j][k];
			}
		}

		for (int k = n2; k > 0; k--) {
			ans[k] = TB[k];
			for (int j = n2; j > k; j--) 
				ans[k] -= ans[j] * A[k][j];
			ans[k] /= A[k][k];
		}

		cout << ans[ind[a][b]] << sep;
	}

	cout << endl;
	return 0;
}