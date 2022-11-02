#include <bits/stdc++.h>

using namespace std;
#define int long long

int f(int x) {
	x++;
	while (x % 10 == 0 && x > 0) {
		x /= 10;
	}
	return x;
}

void read() {
	int n;
	string s;
	vector <int> a;
	cin >> n >> s;
	a.resize(10);
	for (auto &i : a)
		cin >> i;
	bool flag = false;
	for (int i = 0; i < s.size(); i++) {
		if (flag && a[s[i] - '1'] < s[i] - '0') {
			for (int j = i; j < s.size(); j++)
				cout << s[j];
			return;
		}
		if (a[s[i] - '1'] > s[i] - '0') {
			flag = true;
			cout << a[s[i] - '1'];
		}
		else {
			cout << s[i];
		}
	}
}

void run() {

}

void write() {

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}