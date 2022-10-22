#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool can = false;
		for (int j = 0; j <= n - 11; j++) {
			if (s[j] == '8') {
				can = true;
				break;
			}
		}
		cout << (can ? "YES" : "NO") << "\n";
	}
}