#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 100010
int n;
int f[N];
int g[N], h[N];
int A[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> f[i];
		f[i] --;
	}
	for (int i = 0; i < n; i ++)
		if (f[f[i]] != f[i]) {
			puts ("-1");
			return 0;
		}
	int m = 0;
	for (int i = 0; i < n; i ++)
		if (f[i] == i) A[m++] = i;
	memset(g, -1, sizeof g);
	for (int i = 0; i < m; i ++) {
		g[A[i]] = i;
		h[i] = A[i];
	}
	for (int i = 0; i < n; i ++)
		g[i] = g[f[i]];
	printf ("%d\n", m);
	for (int i = 0; i < n; i ++)
		printf ("%d%c", g[i]+1, i == n-1?'\n':' ');
	for (int i = 0; i < m; i ++)
		printf ("%d%c", h[i]+1, i == m-1?'\n':' ');
	return 0;
}