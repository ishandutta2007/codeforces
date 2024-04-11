#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define INF 1000000000

int main() {
	int le = -INF, ri = INF;
	int n; cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		if (y == 2) {
			ri = min(ri, 1899);
		} else {
			le = max(le, 1900);
		}
		le += x;
		ri += x;
	}
	if (le > ri) {
		puts ("Impossible");
	} else
	if (ri >= INF/2) {
		puts ("Infinity");
	} else {
		cout << ri << endl;
	}
	return 0;
}