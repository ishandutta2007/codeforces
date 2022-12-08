#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
bool pcomp(pair<int, int> f, pair<int, int> s) {
	if (f.first == s.first) return f.second < s.second;
	return f.first < s.first;
}
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	int a, b;
	int last = -1;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		pair<int, int> temp = make_pair(a,b);
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), pcomp);
	for (int i = 0; i < n; i++) {
		if (v[i].second >= last) last = v[i].second;
		else last = v[i].first;
	}
	cout << last << endl;
	// cin >> n;

}