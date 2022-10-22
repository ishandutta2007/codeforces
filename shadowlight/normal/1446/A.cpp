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
	ll w;
	cin >> n >> w;
	vector <ll> a(n);
	vector <int> indexes;
	int index = -1;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] > w) continue;
		if (a[i] >= (w + 1) / 2) {
			index = i;
		} else if (a[i] <= (w + 1) / 2) {
			indexes.pb(i);
		}
	}
	if (index != -1) {
		cout << "1\n";
		cout << index + 1 << "\n";
		return;
	}
	vector <int> tt;
	ll now = 0;
	for (int x : indexes) {
		now += a[x];
		tt.pb(x);
		if (now >= (w + 1) / 2) {
			break;
		}
	}
	if (now < (w + 1) / 2) {
		cout << "-1\n";
		return;
	}
	cout << tt.size() << "\n";
	for (int x : tt) {
		cout << x + 1 << " ";
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
	for (int i = 0; i < t; ++i) {
		solve();
	}

}