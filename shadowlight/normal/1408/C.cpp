#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const db EPS = 1e-8;

void solve() {
	int n, l;
	cin >> n >> l;
	vector <int> a(n + 2);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	a[0] = 0, a[n + 1] = l;
	int lt = 0, rt = n + 1;
	int v1 = 1, v2 = 1;
	db res = 0;
	db pos1 = 0, pos2 = l;
	for (int i = 0; ; ++i) {
		if (rt - lt <= 1) {
			//cout << pos1 << " " << pos2 << endl;
			res += (pos2 - pos1) / (db)(v1 + v2);
			break;
		}
		db tm = min((a[lt + 1] - pos1) / v1, (pos2 - a[rt - 1]) / v2);
		pos1 += v1 * tm;
		pos2 -= v2 * tm;
		res += tm;
		if (abs(a[lt + 1] - pos1) < EPS) {
			++lt;
			++v1;
		}
		if (abs(a[rt - 1] - pos2) < EPS) {
			--rt;
			++v2;
		}
	}
	cout.precision(20);
	cout << fixed << res << "\n";
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
	for (int i = 0; i < t; ++i) {
		solve();
	}

}