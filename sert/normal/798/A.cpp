#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int num = 0, n = s.length();
	for (int i = 0; i < n / 2; i++)
		if (s[i] != s[n - i - 1])
			num++;
	if (num == 0 && n % 2 == 0) {
		cout << "NO";
		return 0;
	}
	cout << (num <= 1 ? "YES\n" : "NO\n");
	return 0;
}