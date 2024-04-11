#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100009], b[100009], c[100009];
int main() {
	cin >> n;
	map<pair<int, int>, vector<pair<int, int> > > d;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		d[make_pair(a[i], b[i])].push_back(make_pair(c[i], i));
		d[make_pair(b[i], c[i])].push_back(make_pair(a[i], i));
		d[make_pair(c[i], a[i])].push_back(make_pair(b[i], i));
		d[make_pair(a[i], c[i])].push_back(make_pair(b[i], i));
		d[make_pair(b[i], a[i])].push_back(make_pair(c[i], i));
		d[make_pair(c[i], b[i])].push_back(make_pair(a[i], i));
	}
	vector<int> r; int ret = 0;
	for (map<pair<int, int>, vector<pair<int, int> > >::iterator it = d.begin(); it != d.end(); it++) {
		sort((*it).second.begin(), (*it).second.end());
		(*it).second.erase(unique((*it).second.begin(), (*it).second.end()), (*it).second.end());
		int f = min((*it).first.first, (*it).first.second);
		if ((*it).second.size() == 1) {
			f = min(f, (*it).second[0].first);
			if (ret < f) {
				r = { (*it).second[0].second };
				ret = f;
			}
		}
		else {
			pair<int, int> e1 = (*it).second[(*it).second.size() - 1];
			pair<int, int> e2 = (*it).second[(*it).second.size() - 2];
			f = min(f, e1.first + e2.first);
			if (ret < f) {
				r = { e1.second, e2.second };
				ret = f;
			}
		}
	}
	cout << r.size() << endl;
	for (int i = 0; i < r.size(); i++) {
		if (i) cout << ' ';
		cout << r[i] + 1;
	}
	cout << endl;
	return 0;
}