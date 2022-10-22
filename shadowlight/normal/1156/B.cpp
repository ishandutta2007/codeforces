#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int Q = 31;

void solve() {
	string s;
	cin >> s;
	vector <int> cnt(Q, 0);
	set <int> q;
	for (char c : s) {
		cnt[c - 'a']++;
		q.insert(c - 'a');
	}
	vector <int> a, b;
	int tp = 0;
	for (int x : q) {
		if (!tp) {
			a.push_back(x);
		} else {
			b.push_back(x);
		}
		tp = 1 - tp;
	}
	if (q.size() == 2 && abs(a[0] - b[0]) == 1) {
		cout << "No answer\n";
		return;
	}
	if (q.size() == 3 && abs(a[0] - b[0]) == 1 && abs(a[1] - b[0]) == 1) {
		cout << "No answer\n";
		return;
	}
	string res = "";
	for (int x : b) {
		while (cnt[x]) {
			res += (char) (x + 'a');
			cnt[x]--;
		}
	}
	if (q.size() == 3) {
		if (abs(a[0] - b[0]) == 1) {
			swap(a[0], a[1]);
		}
	}
	for (int x : a) {
		while (cnt[x]) {
			res += (char) (x + 'a');
			cnt[x]--;
		}
	}
	cout << res << "\n";
}

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}