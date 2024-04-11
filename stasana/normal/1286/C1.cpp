#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

const ll INF = (ll)(1e17) + 666;

void start() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
}

string sub(string a, string b) {
	string result;
	ll ptr = 0;
	for (char ch : a) {
		if (ptr < b.size() && ch == b[ptr]) {
			++ptr;
		} else {
			result.push_back(ch);
		}
	}
	return result;
}

void solve() {
	ll n;
	cin >> n;
	cout << "? " << 1 << " " << n << endl;
	vector<vector<string>> a(n);
	for (ll i = 0; i < n * (n + 1) / 2; ++i) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		a[(ll)s.size() - 1].emplace_back(s);
	}
	string all = a[n - 1][0];
	if (n == 1) {
		cout << "! " << all << endl;
		return;
	}
	cout << "? " << 1 << " " << n - 1 << endl;
	for (ll j = 0; j < (n - 1) * n / 2; ++j) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		ll m = (ll)s.size() - 1;
		for (ll i = 0; ; ++i) {
			if (a[m][i] == s) {
				swap(a[m][i], a[m][a[m].size() - 1]);
				a[m].pop_back();
				break;
			}
		}
	}
	string result;
	while (all.size() > 1) {
		string new_all = a[all.size() - 2][0];
		string new_char = sub(all, new_all);
		result += new_char;
		all = new_all;
	}
	string end = a[0][0];
	result += end;
	cout << "? " << n << " " << n << endl;
	string end0;
	cin >> end0;
	if (end0 != end) {
		reverse(result.begin(), result.end());
	}
	cout << "! " << result << endl;
}

int main() {
	start();
	solve();
	return 0;
}

/*
3
a
b
c
ac
cb
abc
*/