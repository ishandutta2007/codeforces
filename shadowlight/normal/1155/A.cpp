#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] > s[i + 1]) {
			cout << "YES\n";
			cout << i + 1 << " " << i + 2 << "\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}