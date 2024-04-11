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

#define N 2010
int n, m;
int a[N];
int b[N];
bool c[N];

int ff() {
	for (int i = 0; i < n*2; i ++)
		if (!c[i] && b[i] != -1 && a[i] >= a[b[i]]) return i;
	int x = -1;
	for (int i = 0; i < n*2; i ++)
		if (!c[i] && (x == -1 || a[i] > a[x])) x = i;
	return x;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n*2; i ++)
		cin >> a[i];
	memset(b, -1, sizeof b);
	for (int i = 0; i < m; i ++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		b[x] = y;
		b[y] = x;
	}
	int t;
	cin >> t;
	for (int i = 0; i < n; i ++) {
		if (t == 1) {
			int x = ff();
			c[x] = true;
			cout << x+1 << endl;
			cout.flush();

			int y; cin >> y; y--;
			c[y] = true;
		} else {
			int y; cin >> y; y--;
			c[y] = true;
			int x;
			if (b[y] != -1 && !c[b[y]]) {
				x = b[y];
			} else {
				x = ff();
			}
			c[x] = true;
			cout << x+1 << endl;
			cout.flush();
		}
	}
	return 0;
}