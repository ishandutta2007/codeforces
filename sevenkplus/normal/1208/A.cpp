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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int _;
	cin >> _;
	while (_--) {
		int a, b, n;
		cin >> a >> b >> n;
		vector<int> c{a, b, a^b};
		printf("%d\n", c[n%3]);
	}
	return 0;
}