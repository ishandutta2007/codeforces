#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1009];
int main() {
	cin >> n;
	map<int, int> d;
	for (int i = 0; i < n; i++) cin >> a[i], d[a[i]]++;
	set<pair<int, int> > s;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (s.count(make_pair(a[i], a[j]))) continue;
			s.insert(make_pair(a[i], a[j]));
			vector<int> v = { a[i], a[j] }; d[a[i]]--; d[a[j]]--;
			for (int k = 2; ; k++) {
				v.push_back(v[k - 2] + v[k - 1]);
				if (abs(v.back()) > 1000000000 || !d[v.back()]) {
					ret = max(ret, k);
					for (int l = 0; l < k; l++) d[v[l]]++;
					break;
				}
				else d[v.back()]--;
			}
		}
	}
	cout << ret << endl;
	return 0;
}