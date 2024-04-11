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
	vector <pair <int, int> > a;
	for (int i = 0; i < n; i++) {
		a.push_back({s[i] - '0', -i});
	}
	sort(a.begin(), a.end());
	int max_pref = 0;
	int last = -1, val = -1;
	int tp = 1;
	vector <int> col(n, 0);
	int nxt_last = -1;
	for (int i = 0; i < n; i++) {
		if (a[i].first > val) {
			last = nxt_last;
			nxt_last = -a[i].second;
			val = a[i].first;
		}
		if (-a[i].second <= last) {
			tp++;
			nxt_last = -a[i].second;
			last = -1;
		}
		col[-a[i].second] = tp;
		//cout << a[i].first << " " << a[i].second << " " << tp << "\n";
	}
	if (tp > 2) {
		cout << "-\n";
		return;
	}
	for (int x : col) {
		cout << x;
	}
	cout << "\n";
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