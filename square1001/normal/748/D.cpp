#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int n, m, a[100009]; string s[100009], rs[100009]; map<string, vector<int> > d[2], e;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> a[i]; rs[i] = s[i];
		reverse(rs[i].begin(), rs[i].end());
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == rs[i]) e[s[i]].push_back(a[i]);
		else {
			if (s[i] > rs[i]) d[1][rs[i]].push_back(a[i]);
			else d[0][s[i]].push_back(a[i]);
		}
	}
	int sum = 0;
	for (pair<string, vector<int> > x : d[0]) {
		vector<int> z1 = x.second;
		vector<int> z2 = d[1][x.first];
		sort(z1.begin(), z1.end(), greater<int>());
		sort(z2.begin(), z2.end(), greater<int>());
		int res = 0, s = 0;
		for (int i = 0; i < z1.size() && i < z2.size(); i++) {
			s += z1[i] + z2[i];
			res = max(res, s);
		}
		sum += res;
	}
	int dm = 0;
	for (pair<string, vector<int> > x : e) {
		vector<int> z = x.second;
		sort(z.begin(), z.end(), greater<int>());
		int res = 0, res2 = 0, s = 0;
		for (int i = 0; i < z.size(); i++) {
			s += z[i];
			res2 = max(res2, s);
			if (i & 1) res = max(res, s);
		}
		sum += res;
		dm = max(dm, res2 - res);
	}
	cout << sum + dm << endl;
	return 0;
}