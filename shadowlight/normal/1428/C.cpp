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
	vector <char> a;
	for (char c : s) {
		if (!a.size()) {
			a.pb(c);
		} else {
			if (c == 'B' && a.back() == 'A') {
				a.pop_back();
			} else if (c == 'B' && a.back() == 'B') {
				a.pop_back();
			} else {
				a.pb(c);
			}
		}
	}
	cout << a.size() << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}

}