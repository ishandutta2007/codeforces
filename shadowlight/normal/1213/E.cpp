#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	cout << "YES\n";
	if (s[0] == s[1] && t[0] == t[1]) {
		for (int i = 0; i < n; i++) {
			cout << "abc";
		}
		cout << "\n";
		return 0;
	}
	if (s[0] == s[1]) {
		for (int i = 0; i < n; i++) {
			cout << t[1] << t[0] << (char) ('a' + 'b' + 'c' - t[0] - t[1]);
		}
		cout << "\n";
		return 0;
	}
	if (t[0] == t[1]) {
		for (int i = 0; i < n; i++) {
			cout << s[1] << s[0] << (char) ('a' + 'b' + 'c' - s[0] - s[1]);
		}
		cout << "\n";
		return 0;
	}
	set <char> q;
	for (char c : s) {
		q.insert(c);
	}
	for (char c : t) {
		q.insert(c);
	}
	if (q.size() == 2) {
		char x = s[0], y = s[1], z = 'a' + 'b' + 'c' - x - y;
		for (int i = 0; i < n; i++) {
			cout << x;
		}
		for (int i = 0; i < n; i++) {
			cout << z;
		}
		for (int i = 0; i < n; i++) {
			cout << y;
		}
		return 0;
	}
	char x = 'd';
	for (x = 'a'; x <= 'c'; x++) {
		if (x == s[0] || x == t[0]) {
			continue;
		}
		break;
	}
	char y = 'd';
	for (y = 'a'; y <= 'c'; y++) {
		if (y == x || y == s[1] || y == t[1]) {
			continue;
		}
		break;
	}
	char z = 'a' + 'b' + 'c' - x - y;
	for (int i = 0; i < n; i++) {
		cout << x;
	}
	for (int i = 0; i < n; i++) {
		cout << z;
	}
	for (int i = 0; i < n; i++) {
		cout << y;
	}
	cout << "\n";
	return 0;
}