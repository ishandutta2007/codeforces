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
	sort(all(a));
	int res = 0;
	for (int i = 1; i < n; ++i) {
		int need = (k - a[i]) / a[0];
		res += need;	
	}
	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		solve();
	}

}