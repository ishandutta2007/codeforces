#include <map>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	map<int, vector<int> > d;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		d[x].push_back(i);
	}
	long long ans = 0.0;
	for (pair<int, vector<int> > i : d) {
		vector<int> v = i.second;
		v.insert(v.begin(), -1);
		v.push_back(n);
		ans += (long long)(n) * n;
		for (int j = 1; j < v.size(); ++j) {
			ans -= (long long)(v[j] - v[j - 1] - 1) * (v[j] - v[j - 1] - 1);
		}
	}
	cout.precision(15);
	cout << double(ans) / n / n << endl;
	return 0;
}