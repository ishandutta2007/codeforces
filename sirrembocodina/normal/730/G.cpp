#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

bool empty(vector<pair<ll, ll> > &a, ll l, ll r) {
	for (int i = 0; i < a.size(); ++i) {
		if (a[i].first > r) continue;
		if (a[i].second < l) continue;
		return false;
	}
	return true;
}

int main() {
	vector<pair<ll, ll> > a;
	vector<ll> ends;
	ends.push_back(1);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll l, r;
		cin >> l >> r;
		r += l - 1;
		if (empty(a, l, r)) {
			a.push_back(make_pair(l, r));
			ends.push_back(r+1);
			cout << l << " " << r << endl;
		} else {
			int j = 0;
			for (j = 0; j < ends.size(); ++j) {
				if (empty(a, ends[j], ends[j] + r - l)) break;
			}
			a.push_back(make_pair(ends[j], ends[j] + r - l));
			ends.push_back(ends[j] + r - l +1);
			cout << ends[j] << " " << ends[j] + r - l << endl;
		}
		sort(ends.begin(), ends.end());
	}
}