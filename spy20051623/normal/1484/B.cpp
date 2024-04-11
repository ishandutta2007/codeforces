#include <bits/stdc++.h>
using namespace std;
int a[100005];
set<int> s;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, maxm;
	cin >> t;
	while (t--) {
		cin >> n;
		s.clear();
		maxm = 0;
		for (i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] > maxm)
				maxm = a[i];
		}
		for (i = 1; i < n; ++i)
			s.insert(a[i] - a[i - 1]);
		if (s.size() > 2)
			cout << -1 << endl;
		else if (s.size() <= 1)
			cout << 0 << endl;
		else if (s.find(0) != s.end())
			cout << -1 << endl;
		else {
			auto it = s.begin();
			if (*it > 0)
				cout << -1 << endl;
			else {
				int tmp = -*it;
				++it;
				if (*it < 0)
					cout << -1 << endl;
				else {
					tmp += *it;
					if (tmp < maxm)
						cout << -1 << endl;
					else
						cout << tmp << ' ' << *it << endl;
				}
			}
		}
	}
	return 0;
}