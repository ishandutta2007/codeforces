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
	int n, m;
	cin >> n >> m;
	bool can = false;
	for (int i = 0; i < n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (b == c) {
			can = true;
			//break;
		}
	}
	if (can && m % 2 == 0) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
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