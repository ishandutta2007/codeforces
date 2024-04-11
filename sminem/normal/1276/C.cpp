#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
int a[400005], b[400005];
int c[400005], d[400005], e[400005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	copy(a, a+n, b);
	sort(b, b+n);
	int k = unique(b, b+n) - b;
	for (int i=0; i<n; i++)
		c[i] = lower_bound(b, b+k, a[i]) - b;

	for (int i=0; i<n; i++)
		d[c[i]]++;

	for (int i=0; i<n; i++)
		e[d[i]]++;

	for (int i=n; i>=1; i--)
		e[i] += e[i+1];

	int zb = 0, xx = 0, yy = 0;
	for (int x=1; x<=n; x++) {
		zb += e[x];
		int y = zb / x;
		if (y < x)
			continue;
		if (x * y > xx * yy)
			xx = x, yy = y;
	}

	// xx <= yy
	vector<vector<int>> sol(xx, vector<int>(yy, 0));
	int rr = 0, cc = 0;

	vector<pair<int, int>> stavi;

	for (int i=0; i<k; i++) {
		int amt = min(xx, d[i]);
		stavi.emplace_back(amt, b[i]);
	}

	sort(stavi.begin(), stavi.end(), greater<pair<int, int>>());

	for (auto [amt, bi] : stavi) {
		while (amt--) {
			sol[rr][(rr+cc) % yy] = bi;
			rr = rr + 1;
			if (rr == xx)
				rr = 0, cc++;
		}
	}

	cout << xx*yy << '\n' << xx << ' ' << yy << '\n';

	for (int i=0; i<xx; i++)
		for (int j=0; j<yy; j++)
			cout << sol[i][j] << " \n"[j == yy-1];
}