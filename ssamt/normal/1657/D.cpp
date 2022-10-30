#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	long long i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	int mc;
	cin >> n >> mc;
	vector<vector<long long>> unit;
	for(i=0; i<n; i++) {
		long long c, d, h;
		cin >> c >> d >> h;
		unit.push_back({c, d*h});
	}
	sort(unit.begin(), unit.end());
	vector<long long> deal(mc+1, 0);
	for(i=0; i<n; i++) {
		if(i == n-1 || unit[i][0] != unit[i+1][0]) {
			int c = unit[i][0];
			long long pow = unit[i][1];
			for(j=1; j*c<=mc; j++) {
				deal[j*c] = max(deal[j*c], j*pow);
			}
		}
	}
	for(i=1; i<=mc; i++) {
		deal[i] = max(deal[i-1], deal[i]);
	}
	cin >> m;
	for(i=0; i<m; i++) {
		long long d, h;
		cin >> d >> h;
		int idx = upper_bound(deal.begin(), deal.end(), d*h)-deal.begin();
		if(idx == deal.size()) {
			idx = -1;
		}
		cout << idx << " ";
	}
}