#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a = 0, b = 0;
	for (char c : s) {
		if (c == '(') {
			if (a < b) {
				a++;
				cout << "0";
			} else {
				b++;
				cout << "1";
			}
		} else {
			if (a < b) {
				b--;
				cout << "1";
			} else {
				a--;
				cout << "0";
			}
		}
	}
}