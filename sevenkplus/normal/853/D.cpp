#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pct __builtin_popcount

#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (__typeof((c).begin()) i=((c).begin()); i!=((c).end()); i++)

#define INF 1000000007
#define M 41
#define N 300010
int f[M], f0[M];
int n, a[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%d", a+i);
		a[i] /= 100;
	}
	for (int j = 0; j < M; j ++) f[j] = INF;
	f[0] = 0;
	for (int i = 0; i < n; i ++) {
		memcpy(f0, f, sizeof f);
		for (int j = 0; j < M; j ++) f[j] = INF;
		for (int j = 0; j < M; j ++)
			if (f0[j] != INF) {
				// spend
				int u = min(a[i], j);
				f[j-u] = min(f[j-u], f0[j] + a[i]-u);
				// no spend
				int j1 = j+a[i]/10;
				if (j1 < M) f[j1] = min(f[j1], f0[j] + a[i]);
			}
	}
	int S = INF;
	for (int j = 0; j < M; j ++)
		S = min(S, f[j]);
	printf ("%d\n", S*100);
	return 0;
}