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
	int n, m;
	cin >> n >> m;
	vector <int> a(n), b(m), pos(n, -1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		pos[a[i]] = i;
	}
	ll res = 0, now = -1;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		x--;
		if (now >= pos[x]) {
			res++;
			continue;
		}
		now = pos[x];
		res += 2 * (pos[x] - i) + 1;
		//cout << pos[x] << " " << res << "\n";
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