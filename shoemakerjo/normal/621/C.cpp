#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, p;
	cin >> n >> p;
	double prob[n];
	double ans = 0.0;
	int l, r;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		int st = l/p;
		if (l %p != 0) st++;
		int en = r/p;
		int ok = en-st+1;
		prob[i] = (ok+0.0)/(r-l+1.0);
		
	}
	for (int i = 0; i < n; i++) {
		int pa = (i+1)%n;
		double pos = 1.0-(1.0-prob[i])*(1.0-prob[pa]);
		ans += 2000.0*pos;
	}

	cout << fixed << setprecision(10);
	cout << ans << endl;
	cin >> ans;
}