#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
	int x;
	cin >> x;
	int t = 0;
	while (t < 1000 && t * (t - 1) / 2 <= x) t++;
	int a = 1;
	if (t * (t + 1) / 2 <= x) {
		while (t * (t - 1) / 2 * a <= x) a++;
		a--;
	} else {
		t--;
	}
	vector <int> need_one(a, t);
	x -= a * t * (t - 1) / 2;
	//cout << x << "\n";
	while (x > 0) {
		if (t * (t - 1) / 2 > x) {
			t--;
			continue;
		}
		need_one.push_back(t);
		x -= t * (t - 1) / 2;
	}
	int now = need_one[0];
	for (int x : need_one) {
		while (now > x) {
			cout << "3";
			now--;
		}
		cout << "1";
	}
	while (now) {
		cout << "3";
		now--;
	}
	cout << "7\n";
}

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}