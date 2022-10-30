#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int get_median(vector<int> v) {
	sort(v.begin(), v.end());
	int n = v.size();
	return v[n / 2];
}
vector<pair<int, int> > get_path(int sx, int sy, int gx, int gy) {
	vector<pair<int, int> > v;
	for (int i = min(sx, gx); i <= max(sx, gx); ++i) {
		v.push_back(make_pair(i, sy));
	}
	for (int i = min(sy, gy); i <= max(sy, gy); ++i) {
		if (i != sy) v.push_back(make_pair(gx, i));
	}
	return v;
}
int main() {
	vector<int> X(3), Y(3);
	for (int i = 0; i < 3; ++i) {
		cin >> X[i] >> Y[i];
	}
	int mx = get_median(X);
	int my = get_median(Y);
	vector<pair<int, int> > v;
	for (int i = 0; i < 3; ++i) {
		vector<pair<int, int> > res = get_path(mx, my, X[i], Y[i]);
		v.insert(v.end(), res.begin(), res.end());
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	cout << v.size() << endl;
	for (pair<int, int> i : v) {
		cout << i.first << ' ' << i.second << endl;
	}
	return 0;
}