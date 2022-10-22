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
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int diff = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] != a[i - 1]) {
			++diff;
		}
	}
	if (k == 1 && diff > 1) {
		cout << "-1\n";
		return;
	} else if (k == 1 || diff == 1) {
		cout << "1\n";
		return;
	} 
	int t = (diff - 1) / (k - 1);
	//cout << diff - 1 << " " << k - 1 << endl;
	if ((diff - 1) % (k - 1)) {
		++t;
	}
	cout << t << "\n";
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