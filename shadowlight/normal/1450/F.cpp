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
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}

	vector <int> cnt(n, 0);
	int bad = 1;

	for (int i = 0; i < n - 1; ++i) {
		if (a[i] == a[i + 1]) {
			++bad;
			++cnt[a[i]];
			++cnt[a[i + 1]];
		}
	}
	++cnt[a[0]];
	++cnt[a[n - 1]];
	int j = 0;
	for (int i = 0; i < n; ++i) {
		if (cnt[i] > cnt[j]) {
			j = i;
		}
	}
	if (cnt[j] <= bad + 1) {
		cout << bad - 1 << "\n";
		return;
	}
	int need = cnt[j] - (bad + 1);
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] == a[i + 1]) continue;
		if (a[i] == j || a[i + 1] == j) continue;
		--need;
		++bad;
		if (!need) break;
	}
	if (need) {
		//cout << "NEED:" << need << "\n";
		cout << "-1\n";
	} else {
		cout << bad - 1 << "\n";
	}
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}