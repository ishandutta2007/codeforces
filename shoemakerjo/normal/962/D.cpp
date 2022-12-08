#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pli pair<ll, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ll ans[n];
	fill(ans, ans+n, -1);
	ll cur;
	priority_queue<pli, vector<pli>, greater<pli>> pq;

	for (int i = 0; i < n; i++) {
		cin >> cur;
		pq.push(pli(cur, i));
	}
	while (!pq.empty()) {
		pli fi = pq.top(); pq.pop();
		if (pq.empty() || pq.top().first != fi.first) {
			ans[fi.second] = fi.first;
			// cout << fi.first << "  placed at  " << fi.second << endl;
			continue;
		}
		pli se = pq.top(); pq.pop();
		assert(fi.first == se.first);
	

		fi.second = fi.second;
		se.second = se.second; //want it normal now
		// cout << fi.first << " " << fi.second << " " << se.second << endl;
		ll nx = fi.first*2LL;
		ans[fi.second] = -1LL;
		pq.push(pli(nx, se.second));

	}
	vector<ll> pa;
	for (int i = 0; i < n; i++) {
		if (ans[i] != -1) pa.push_back(ans[i]);
	}
	cout << pa.size() << endl;
	for (int i = 0; i < pa.size(); i++) {
		cout << pa[i] << " ";
	}
	cout << endl;
	cin >> n;

}