#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	vector<set<char> > v(k);
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (j < k && v[j].count(s[i]) > 0) {
			j++;
		}
		if (j == k) {
			cout << "NO" << endl;
			exit(0);
		}
		v[j].insert(s[i]);
	}
	cout << "YES" << endl;
	exit(0);
}