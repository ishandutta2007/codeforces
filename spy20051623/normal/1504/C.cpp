#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, i, j, k;
	deque<int> q1, q2;
	cin >> n;
	string s, s1(n, '0'), s2(n, '0');
	cin >> s;
	for (i = 0; i < n; ++i) {
		if (s[i] == '0')
			q1.push_back(i);
		else
			q2.push_back(i);
	}
	if (q1.size() % 2) {
		cout << "NO" << endl;
		return;
	}
	k = 0;
	while (!q1.empty()) {
		i = q1.front();
		j = q1.back();
		q1.pop_front();
		q1.pop_back();
		if (!k) {
			s1[i] = '(';
			s2[i] = ')';
			s1[j] = ')';
			s2[j] = '(';
		} else {
			s1[i] = ')';
			s2[i] = '(';
			s1[j] = '(';
			s2[j] = ')';
		}
		k ^= 1;
	}
	while (!q2.empty()) {
		i = q2.front();
		j = q2.back();
		q2.pop_front();
		q2.pop_back();
		s1[i] = '(';
		s2[i] = '(';
		s1[j] = ')';
		s2[j] = ')';
	}
	k = 0;
	for (i = 0; i < n; ++i) {
		if (s1[i] == '(')
			++k;
		else
			--k;
		if (k < 0) {
			cout << "NO" << endl;
			return;
		}
	}
	k = 0;
	for (i = 0; i < n; ++i) {
		if (s2[i] == '(')
			++k;
		else
			--k;
		if (k < 0) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	cout << s1 << endl;
	cout << s2 << endl;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}