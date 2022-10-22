#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int cnt = 0;
	for (char c : s) {
		if (c == 'a') {
			cnt++;
		}
	}
	if (cnt > s.size() / 2) {
		cout << s.size() << "\n";
		return 0;
	}
	cout << 2 * cnt - 1 << "\n";
}