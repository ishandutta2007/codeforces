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

#define N 110
int f[N][N*N];
int a[N];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		a[x] ++;
	}
	f[0][0] = 1;
	for (int i = 1; i <= 100; i ++) if (a[i]) {
		for (int j = 100; j >= 0; j--)
			for (int k = 0; k <= j*100; k ++) if (f[j][k])
				for (int l = 1; l <= a[i]; l ++)
					f[j+l][k+i*l] = min(f[j+l][k+i*l] + f[j][k], 2);
	}
	int S = 0;
	for (int i = 1; i <= 100; i ++)
		for (int l = 1; l <= a[i]; l ++)
			if (f[l][i*l] == 1) S = max(S, l);
	
	int T = 0;
	for (int i = 1; i <= 100; i ++)
		if (a[i]) T++;
	if (T <= 2) S = n;

	cout << S << endl;
	return 0;
}