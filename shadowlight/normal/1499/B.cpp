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

	bool has_one = false;

	int n = s.size();

	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == s[i + 1] && s[i] == '1') {
			has_one = true;
		}
		if (has_one && s[i] == s[i + 1] && s[i] == '0') {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}