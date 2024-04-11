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
	int opena = 0, openb = 0;
	int res = 0;
	for (char c : s) {
		if (c == '(') {
			++opena;
		}
		if (c == '[') {
			++openb;
		}
		if (c == ')') {
			if (opena) {
				++res, --opena;
			}
		}
		if (c == ']') {
			if (openb) {
				++res, --openb;
			}
		}
	}
	cout << res << "\n";
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