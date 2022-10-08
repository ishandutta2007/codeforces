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
int a[N];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	int S = 0, T = 0;
	vector<int> c;
	for (int i = 0; i < n; i ++) {
		S += a[i];
		if (i == 0 || a[0] >= a[i]*2) {
			T += a[i];
			c.pb(i);
		}
	}
	if (T > S-T) {
		int m = c.size();
		printf("%d\n", m);
		for (int i = 0; i < m; i ++)
			printf("%d%c", c[i]+1, i == m-1?'\n':' ');
	} else {
		puts ("0");
	}
	return 0;
}