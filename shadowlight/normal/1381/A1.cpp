#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

string a, b;

void op(int len) {
	for (int i = 0; i < len; ++i) {
		a[i] = (a[i] == '1' ? '0' : '1');
	}
	for (int i = 0; i < len / 2; ++i) {
		swap(a[i], a[len - i - 1]);
	}
}

void solve() {
	int n;
	cin >> n;
	cin >> a >> b;
	vector <int> res;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == b[i]) continue;
		if (a[0] == b[i]) {
			op(1);
			res.pb(1);
		}
		op(i + 1);
		res.pb(i + 1);
	}
	assert(a == b);
	cout << res.size() << " ";
	for (int x : res) {
		cout << x << " ";
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