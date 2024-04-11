#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	set<set<int>> s;
	for (int i = 0; i < n; i++) {
		if (v[i] > 0) {
			set<int> t;
			for (auto x : v) {
				if (x >= v[i]) {
					t.insert(x);
				}
			}
			s.insert(t);
		}
	}
	cout << s.size() << endl;

	exit(0);
}