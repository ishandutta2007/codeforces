#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int n;
	string s;
	cin >> n;
	getline(cin, s);
	getline(cin, s);
	int l = 0;
	vector<int> a;
	forn (i, s.size()) {
		if (s[i] == '.' || s[i] == '!' || s[i] == '?') {
			a.push_back(i - l + 1);
			l = i + 2;
		}
	}
	int k = -1;
	int ans = 0;
	forn (i, a.size()) {
		if (a[i] > n) {
			cout << "Impossible";
			return 0;
		}
		if (k + a[i] + 1 > n) {
			ans++;
			k = a[i];
		} else {
			k += a[i] + 1;
		}
	}
	ans++;
	cout << ans;
}