#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

const int inf = 30000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int maxa = -inf;
	int maxb = -inf;

	int minx = inf;
	int miny = inf;

	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		minx = min(minx, x);
		miny = min(miny, y);
	}
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		maxa = max(maxa, a);
		maxb = max(maxb, b);
	}


	cout << minx + maxa << " " << miny + maxb << endl;
}