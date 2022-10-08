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
int n;
int a[N];
map<int, int> A;
int t;
int cnt;
int c[N];

void ff() {
	memset(c, 0, sizeof c);
	for (int i = 0; i < n; i ++) {
		c[a[i]]++;
		if (c[a[i]] == 2) cnt++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (A.find(a[i]) == A.end()) {
			A[a[i]] = t++;
		}
		a[i] = A[a[i]];
	}
	int S = 0;
	for (int l = 0; l < n; l ++) {
		ff();
		for (int r = l; r <= n; r ++) {
			if (cnt == 0) S = max(S, n-(r-l));
			if (r == n) break;
			c[a[r]]--;
			if (c[a[r]] == 1) cnt--;
		}
	}
	cout << n-S << endl;
	return 0;
}