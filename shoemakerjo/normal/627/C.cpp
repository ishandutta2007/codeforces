#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int d, n, m;
	cin >> d >> n >> m;
	vector<pii> stations;
	int x, p;
	for (int i = 0; i < m; i++) {
		cin >> x >> p;
		stations.push_back(pii(x, p));
	}
	stations.push_back(pii(0, 0)); //gas price zero at the beginning 
	stations.push_back(pii(d, 0));
	sort(stations.begin(), stations.end());
	ll ans = 0LL;
	bool ok = true;
	int cap = 0;
	int nx[stations.size()];
	stack<pii> pric;
	pric.push({0,d}); //price by distance
	for (int i = stations.size()-2; i >= 0; i--) {
		int val = stations[i].second;
		while (val < pric.top().first) pric.pop();
		nx[i] = pric.top().second;
		if (stations[i+1].first - stations[i].first > n) {
			ok = false;
		}
		pric.push({stations[i].second, stations[i].first});
	}
	if (!ok) {
		cout << -1 << endl;
		cin >> d;
		return 0;
	}
	cap = n; //start with n filled
	for (int i = 1; i < stations.size()-1; i++) {
		cap -= stations[i].first - stations[i-1].first;
		int nf = min(n, nx[i]-stations[i].first);
		if (nf < cap) continue;
		ans += (nf-cap-0LL)*(stations[i].second+0LL);
		cap = nf;
	}
	cout << ans << endl;
	cin >> ans;

}