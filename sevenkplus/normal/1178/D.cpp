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

bool pr(int n) {
	for (int i = 2; i*i <= n; i ++)
		if (n%i == 0) return false;
	return true;
}

int main() {
	int n;
	cin >> n;
	int m = 0;
	for (int i = 0; i <= n/2; i ++)
		if (pr(n + i)) {
			m = i;
			break;
		}
	printf("%d\n", n+m);
	for (int i = 0; i < n; i ++)
		printf("%d %d\n", i+1, (i+1)%n+1);
	for (int i = 0; i < m; i ++)
		printf("%d %d\n", i+1, i+n/2+1);
	return 0;
}