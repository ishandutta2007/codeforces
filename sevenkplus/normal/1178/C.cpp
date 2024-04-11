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

#define P 998244353

int main() {
	int n, m;
	cin >> n >> m;
	int S = 1;
	for (int i = 0; i < n+m; i ++)
		(S *= 2) %= P;
	cout << S << endl;
	return 0;
}