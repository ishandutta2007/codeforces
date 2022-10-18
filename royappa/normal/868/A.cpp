#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;

	string s;
	cin >> s;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	string t = "";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			t += v[i]+v[j];
		}
	}
	for (int i = 0; i < t.size()-2; i++) {
		if (t.substr(i, 2) == s) {
			cout << "YES" << endl;
			exit(0);
		}
	}
	cout << "NO" << endl;
	exit(0);
}