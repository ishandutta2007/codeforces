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
	string s, t;
	cin >> s >> t;
	vector <vector <int> > pos(26);
	for (int i = 0; i < (int) s.size(); i++) {
		pos[s[i] - 'a'].push_back(i);
	}
	int res = 1, now = -1;
	for (int i = 0; i < (int) t.size(); i++) {
		auto &mas = pos[t[i] - 'a'];
		int d = upper_bound(mas.begin(), mas.end(), now) - mas.begin();
		if (!mas.size()) {
			cout << "-1\n";
			return;
		}
		if (mas.size() == d) {
			res++;
			now = mas[0];
		} else {
			now = mas[d];
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
	for (int i = 0; i < t; i++) {
		solve();
	}

}