#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector <int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	if (n == 1) {
		cout << "0 0 0\n";
		return;
	}
	n /= 2;
	vector <int> t;
	for (int i = 0; i < n; i++) {
		if (p[i] > p[i + 1]) {
			t.push_back(i + 1);
		}
	}
	if (!t.size()) {
		cout << "0 0 0\n";
		return;
	}
	int g = t[0];
	int it = 1;
	while (it < (int) t.size() && t[it] <= 2 * g) {
		it++;
	}
	if (it == t.size()) {
		cout << "0 0 0\n";
		return;
	}
	int s = t[it] - g;
	int b = t.back() - s - g;
	if (b <= g) {
		cout << "0 0 0\n";
		return;
	}
	cout << g << " " << s << " " << b << "\n";
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