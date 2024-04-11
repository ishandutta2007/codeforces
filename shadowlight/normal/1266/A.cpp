#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	string s;
	cin >> s;
	if (s == "0") {
		cout << "red\n";
		return;
	}
	int sum = 0;
	vector <int> cnt(10, 0);
	for (char c : s) {
		sum += c - '0';
		cnt[c - '0']++;
	}
	if (!cnt[0]) {
		cout << "cyan\n";
		return;
	}
	cnt[0]--;
	bool can = false;
	for (int i = 0; i < 10; i += 2) {
		if (cnt[i]) {
			can = true;
			break;
		}
	}
	if (can && sum % 3 == 0) {
		cout << "red\n";
		return;
	} else {
		cout << "cyan\n";
		return;
	}
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}