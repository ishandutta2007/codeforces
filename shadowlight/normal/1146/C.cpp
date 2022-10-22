#include <bits/stdc++.h>
#define ll long long

using namespace std;

int query(vector <int> &a, vector <int> &b) {
	if (a.size() < 1 || b.size() < 1) {
		return 0;
	}
	cout << a.size() << " " << b.size() << " ";
	for (int x : a) {
		cout << x + 1 << " ";
	}
	for (int y : b) {
		cout << y + 1 << " ";
	}
	cout << endl;
	int d;
	cin >> d;
	return d;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector <vector <int> > a;
		vector <int> t(n, 0);
		iota(t.begin(), t.end(), 0);
		a.push_back(t);
		int res = 0;
		while (a.size() != n) {
			//cout << "kek " << a.size() << endl;
			vector <vector <int> > na;
			vector <int> q1, q2;
			for (auto mas : a) {
				int sz = mas.size();
				if (sz == 1) {
					na.push_back({mas[0]});
					continue;
				}
				na.push_back({});
				for (int i = 0; i < sz / 2; i++) {
					q1.push_back(mas[i]);
					na.back().push_back(mas[i]);	
				}
				na.push_back({});
				for (int i = sz / 2; i < sz; i++) {
					q2.push_back(mas[i]);
					na.back().push_back(mas[i]);	
				}
			}
			res = max(res, query(q1, q2));
			a = na;
		}
		cout << "-1 " << res << endl;
	}
}