#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	set<int> s;
	int t, n, k, i, j, maxm;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		s.clear();
		maxm = 0;
		while (n--) {
			cin >> i;
			s.insert(i);
			if (i > maxm)
				maxm = i;
		}
		i = 0;
		while (k--) {
			while (s.find(i) != s.end())
				++i;
			if (i == s.size())
				break;
			j = (i + maxm + 1) / 2;
			if (s.find(j) != s.end())
				break;
			s.insert(j);
		}
		if (i == s.size())
			cout << s.size() + k + 1 << endl;
		else
			cout << s.size() << endl;
	}
	return 0;
}