#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e3 + 10;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n;
ld A[MAXN][MAXN], dist[MAXN], B[MAXN], C[MAXN], P[MAXN];
bool marked[MAXN];

int main() {
	fill(dist, dist + MAXN, INF);
	fill(B, B + MAXN, INF);
	fill(P, P + MAXN, 1);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int t;
			scanf("%d", &t);
			A[i][j] = t / 100.0;
		}
	}

	dist[n] = 0; 
	for (int t = 0; t < n; t++) {
		int v = 0;
		for (int i = 1; i <= n; i++) 
			if (dist[i] < dist[v] && !marked[i]) 
				v = i;
		if (v == 0) break;
		marked[v] = true;
		
		for (int u = 1; u <= n; u++) {
			if (marked[u] || B[u] <= dist[v]) continue;
			
			C[u] += P[u] * A[u][v] * dist[v];
			P[u] *= (1 - A[u][v]);	

			dist[u] = (C[u] + 1) * (1 / (1 - P[u]));
			if (A[v][u] > 0) B[u] = min(B[u], dist[u] + 1 / (A[u][v]));
		}
	}
	
	printf("%.10Lf", dist[1]);
	return 0;
}