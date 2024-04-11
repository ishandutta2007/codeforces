#include <bits/stdc++.h>

using namespace std;
typedef long long LL;



int main()
{
	int n;
	cin >> n;
	set<int> s;
	int r;
	cin >> r;
	for (int i = 0; i < r; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	for (int i = 1; i < n; i++) {
		cin >> r;
		set<int> t;
		for (int j = 0; j < r; j++) {
			int x;
			cin >> x;
			if (s.count(x) > 0) {
				t.insert(x);
			}
		}
		s = t;
	}
	vector<int> q(s.begin(), s.end());
	for (int i = 0; i < q.size(); i++) {
		cout << q[i];
		if (i < (int)q.size()-1) cout << " ";
	}
	cout << endl;
	exit(0);
}