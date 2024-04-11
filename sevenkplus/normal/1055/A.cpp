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

int n, m;
int a[N], b[N];

int main() {
	cin >> n >> m;
	m--;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i < n; i ++) cin >> b[i];
	bool F = false;
	if (a[0] && a[m]) F = true;
	for (int i = m+1; i < n; i ++)
		if (a[0] && a[i] && b[i] && b[m]) F = true;
	puts (F?"YES":"NO");
	return 0;
}