#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005];
int maxm[200005];
set<int> s1, s2;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, j, k;
	cin >> t;
	while (t--) {
		cin >> n;
		s1.clear();
		s2.clear();
		for (i = 0; i < n; ++i) {
			cin >> maxm[i];
			s1.insert(i + 1);
			s2.insert(i + 1);
		}
		i = j = 0;
		while (i < n) {
			while (j < n && maxm[j] == maxm[i])
				++j;
			a[i] = b[i] = maxm[i];
			s1.erase(maxm[i]);
			s2.erase(maxm[i]);
			auto it1 = s1.begin();
			auto it2 = s2.lower_bound(maxm[i]);
			if (it2 != s2.begin())
				--it2;
			for (k = i + 1; k < j; ++k) {
				a[k] = *it1;
				++it1;
				s1.erase(a[k]);
				b[k] = *it2;
				--it2;
				s2.erase(b[k]);
			}
			i = j;
		}
		for (i = 0; i < n; ++i)
			cout << a[i] << ' ';
		cout << endl;
		for (i = 0; i < n; ++i)
			cout << b[i] << ' ';
		cout << endl;
	}
	return 0;
}