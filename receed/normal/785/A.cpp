#include<vector>
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string s;
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s[0] == 'T') ans += 4;
		else if (s[0] == 'C') ans += 6;
		else if (s[0] == 'O') ans += 8;
		else if (s[0] == 'D') ans += 12;
		else if (s[0] == 'I') ans += 20;
	}
	cout << ans;
	return 0;
}