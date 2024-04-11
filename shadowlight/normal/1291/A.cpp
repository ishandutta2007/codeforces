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
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector <int> d;
	for (int i = 0; i < n; i++) {
		if ((s[i] - '0') % 2) {
			d.push_back(s[i] - '0');
		}
	}
	if (d.size() < 2) {
		cout << "-1\n";
	} else {
		cout << d[0] << d[1] << "\n";
	}
}

int main(){
#ifdef LOCAL
	freopen("L_input.txt", "r", stdin);
	//freopen("L_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

}