#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 400000 + 10;
const int inf = 1e9;
vector<int> v;
int id(int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}


LL getmax( vector<pair<int,int> > & v1, vector< pair<int,int> > & v2 ) {
	vector<int> mn(N, inf);
	for (auto p: v1) {
		mn[id(p.second)] = min(mn[id(p.second)], p.first);
	}
	for (int i = N - 2; i >= 0; i --) {
		mn[i] = min(mn[i+1], mn[i]);
	}

	int mx = 0;
	for (auto p: v2) {
		int val = max(mn[id(p.second)], p.first);
		mx = max(mx, p.second - val);
	}
	return mx;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i < n; i ++) cin >> b[i];
	vector< pair<int,int> > v1, v2;
	for (int i = 0; i < n; i ++) {
		if (a[i] <= b[i]) v1.push_back({a[i], b[i]});
		else v2.push_back({b[i], a[i]});
		v.push_back(a[i]); v.push_back(b[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()), v.end());
	LL sum = 0;
	for (int i = 0; i < n; i ++) sum += abs(a[i] - b[i]);
	sum -= 2 * max(getmax(v1, v2), getmax(v2, v1));
	cout << sum << endl;
}