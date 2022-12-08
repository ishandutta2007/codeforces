#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	ll wo = 2000000000000000000LL;
	vector<ll> a, b;
	ll cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		a.push_back(cur);
	}
	for (int j = 0; j < m; j++) {
		cin >> cur;
		b.push_back(cur);
	}
	for (int i = 0; i < n; i++) {
		ll bes = -2000000000000000000LL;
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			for (int k = 0; k < m; k++) {
				bes = max(bes, a[j]*b[k]);
			}
		}
		wo = min(wo, bes);
	}
	cout << wo << endl;
	cin >> n;
}