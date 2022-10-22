#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = (int) 1e18 + 7;

main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int r1, r2, r3;
	cin >> r1 >> r2 >> r3;
	int d;
	cin >> d;
	vector <int> a(n + 1, INF);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector <int> pref(n + 2, INF);
	pref[0] = 0;
	for (int i = 0; i < n; ++i) {
		int one_time = a[i] * r1 + r3;
		int two_times = min(r1 + r2, (a[i] + 2) * r1);
		int next_two_times = min(r1 + r2, (a[i + 1] + 2) * r1);
		pref[i + 1] = min(pref[i + 1], pref[i] + min(one_time, two_times + 2 * d) + (i + 1 != n ? d : 0));
		pref[i + 2] = min(pref[i + 2], pref[i] + two_times + next_two_times + 3 * d + (i + 2 != n ? d : 0));
		//cout << "KEK: " << i << " " << pref[i] + two_times + next_two_times + 3 * d + (i + 2 != n ? d : 0) << "\n";
	}
	//cout << "======\n";
	vector <int> suf(n + 1, 0);
	int one_time = a[n - 1] * r1 + r3;
	int two_times = min(r1 + r2, (a[n - 1] + 2) * r1);
	suf[n - 1] = min(one_time, two_times + 2 * d);
	for (int i = n - 2; i >= 0; --i) {
		int one_time = a[i] * r1 + r3;
		int two_times = min(r1 + r2, (a[i] + 2) * r1);
		suf[i] = suf[i + 1] + two_times + 2 * d;
	}
	int res = INF;
	for (int i = 0; i <= n; ++i) {
		//cout << pref[i] << " " << suf[i] << "\n";
		res = min(res, pref[i] + suf[i]);
	}
	cout << res << "\n";

}