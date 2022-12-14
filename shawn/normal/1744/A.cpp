#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<int, int> mp;
int a[100];

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	int _;
	cin >> _;
	while (_--) {
		mp.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			// cout << mp[a[i]] << " \n"[i == n-1];
		}
		string str;
		cin >> str;
		bool ans = true;
		for (int i = 0; i < n; i++) {
			if (!mp[a[i]]) mp[a[i]] = (int)str[i];
			else if (mp[a[i]] != (int)str[i]) {
				ans = false;
				break;
			}
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;	
}