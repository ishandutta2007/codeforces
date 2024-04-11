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
	int n, k;
	cin >> n >> k;
	vector <int> res(k, -1);
	string s;
	cin >> s;
	int zeroes = 0, ones = 0;
	for (int i = 0; i < n; ++i) {
		char c = s[i];
		if (c == '?') continue;
		int x = (c == '0' ? 0 : 1);
		if (res[i % k] != -1 && res[i % k] != x) {
			cout << "NO\n";
			return;
		}
		res[i % k] = x;
	}
	for (int i = 0; i < k; ++i) {
		if (res[i] == 1) {
			ones++;
		} else if (!res[i]) {
			zeroes++;
		}
	}
	if (ones > k / 2 || zeroes > k / 2) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
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
	for (int i = 0; i < t; ++i) {
		solve();
	}

}