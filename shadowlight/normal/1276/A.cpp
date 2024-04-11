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
	int n = s.size();
	vector <bool> banned(n, 0);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s.substr(i, 5) == "twone") {
			banned[i + 2] = true;
			cnt++;
		}
	}
	string t = "";
	vector <int> pos;
	for (int i = 0; i < n; i++) {
		if (!banned[i]) {
			t += s[i];
			pos.push_back(i);
		}
	}
	for (int i = 0; i < (int) t.size(); i++) {
		if (t.substr(i, 3) == "one" || t.substr(i, 3) == "two") {
			banned[pos[i + 1]] = true;
			cnt++;
		}
	}
	cout << cnt << "\n";
	for (int i = 0; i < n; i++) {
		if (banned[i]) {
			cout << i + 1 << " ";
		}
	}
	cout << "\n";
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