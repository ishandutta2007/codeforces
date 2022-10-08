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

#define N 4444444
//4194304
int a[N], f[N], g[N], n;
bool h[N];
bool v[N];

int fa(int x) {
	if (x == f[x]) return x;
	return f[x] = fa(f[x]);
}

int main() {
	scanf("%d", &n);
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%d", a+i);
		g[a[i]] = a[i];
		h[(1<<22)-1-a[i]] = true;
	}
	for (int p = 0; p < (1<<22); p ++) f[p] = p;
	for (int p = 0; p < (1<<22); p ++)
		if (g[p]) {
			for (int i = 0; i < 22; i ++)
				g[p|(1<<i)] = max(g[p|(1<<i)], g[p]);
		}
	for (int i = 0; i < n; i ++) {
		int x = (1<<22)-1-a[i];
		if (g[x]) f[fa(g[x])] = fa(a[i]);
	}
	for (int p = (1<<22)-1; p; p--)
		if (h[p] && pct(p) >= 2 && g[p]) {
			int la = g[p];
			for (int i = 0; i < 22; i ++)
				if ((p>>i)&1) {
					int p1 = p^(1<<i);
					h[p1] = true;
					if (g[p1]) f[fa(g[p1])] = fa(la);
				}
		}
	int S = 0;
	for (int i = 0; i < n; i ++)
		if (!v[fa(a[i])]) {
			v[fa(a[i])] = true;
			S++;
		}
	cout << S << endl;
	return 0;
}