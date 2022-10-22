#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int t = (s.size() - 11) / 2;
	int a = t, b = t;
	for (int i = 0; i < n; i++) {
		if (s[i] == '8') {
			if (!a) {
				cout << "YES\n";
				return 0;
			}
			a--;
		} else {
			if (!b) {
				cout << "NO\n";
				return 0;
			}
			b--;
		}
	}
	cout << "NO\n";
}