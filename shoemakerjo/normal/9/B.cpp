#include <bits/stdc++.h>

using namespace std;

double sq(double x) {
	return (x)*(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, vb, vs;
	cin >> n >> vb >> vs;
	int spots[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> spots[i];
	}
	int ans = 1;
	double mintime = 1e15;
	int x, y;
	cin >> x >> y;
	for (int i = 2; i <= n; i++) {
		double ctim = spots[i]/(vb+0.0);
		ctim += (sqrt(sq(x-spots[i]) + sq(y)))/(vs+0.0);
		if (ctim < mintime) {
			mintime = ctim;
			ans = i;
		}
		else if (mintime == ctim) {
			if (abs(x-spots[i]) < abs(x-spots[ans])) ans = i;
		}
	}
	cout << ans << endl;
	cin >> n;

}