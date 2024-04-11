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

#define P 1000000007
#define N 10010
int f[N];
bool g[N];
vector<int> a[N], b[N];
int n, q;

void add(int x) {
	for (int i = n-x; i >= 0; i--)
		(f[i+x] += f[i]) %= P;
}

void del(int x) {
	for (int i = 0; i <= n-x; i++)
		(f[i+x] += P-f[i]) %= P;
}

int main() {
	cin >> n >> q;
	while (q--) {
		int x, y, z;
		cin >> x >> y >> z;
		x--;
		a[x].pb(z); b[y].pb(z);
	}
	f[0] = 1;
	for (int i = 0; i < n; i ++) {
		for (auto p: a[i]) add(p);
		for (auto p: b[i]) del(p);
		for (int j = 1; j <= n; j ++)
			if (f[j]) g[j] = true;
	}
	vector<int> S;
	for (int i = 1; i <= n; i ++)
		if (g[i]) S.pb(i);
	printf ("%d\n", (int) S.size());
	for (int i = 0; i < (int) S.size(); i ++)
		printf ("%d%c", S[i], i == (int) S.size()-1?'\n':' ');
	return 0;
}