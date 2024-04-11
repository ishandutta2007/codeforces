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

#define N 1010
int n;
int a[N][N];
int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n/2; i ++)
		for (int j = 0; j < n/2; j ++) {
			a[i][j] = t++;
			a[i][j+n/2] = t++;
			a[i+n/2][j] = t++;
			a[i+n/2][j+n/2] = t++;
		}
	for (int i = 0; i < n; i ++) {
		int s = 0;
		for (int j = 0; j < n; j ++) s ^= a[i][j];
		assert(!s);
		int t = 0;
		for (int j = 0; j < n; j ++) t ^= a[j][i];
		assert(!t);
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++)
			printf("%d%c", a[i][j], j == n-1?'\n': ' ');
	}
	return 0;
}