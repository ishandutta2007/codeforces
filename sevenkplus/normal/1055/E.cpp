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

#define INF 1000000007
#define N 1510
int n, m, kk, mm;
int a[N];
int pl[N], pr[N];
int rr[N];

int s[N];
int f[N][N];

bool can(int x) {
	// #( < x) >= kk-1
	s[0] = 0;
	for (int i = 0; i < n; i ++)
		s[i+1] = s[i] + (a[i] <= x);
	memset(f, 0, sizeof f);
	f[0][0] = 0;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j <= mm; j ++) {
			f[i+1][j] = max(f[i+1][j], f[i][j]);
			if (rr[i] != -1 && j < mm) {
				int ii = rr[i]+1;
				int jj = j+1;
				f[ii][jj] = max(f[ii][jj], f[i][j] + s[ii]-s[i]);
			}
		}
	for (int j = 0; j <= mm; j ++)
		if (f[n][j] >= kk) return true;
	return false;
}

int main() {
	cin >> n >> m >> mm >> kk;
	for (int i = 0; i < n; i ++) cin >> a[i];
	memset(rr, -1, sizeof rr);
	for (int i = 0; i < m; i ++) {
		cin >> pl[i] >> pr[i];
		pl[i] --;
		pr[i] --;
		for (int j = pl[i]; j <= pr[i]; j ++)
			rr[j] = max(rr[j], pr[i]);
	}
	int le = 0, ri = INF;
	while (le <= ri) {
		int mi = (le+ri)/2;
		if (can(mi)) ri = mi-1;
		else le = mi+1;
	}
	if (le > INF) le = -1;
	cout << le << endl;
	return 0;
}