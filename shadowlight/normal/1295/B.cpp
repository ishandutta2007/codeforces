#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	int bal = 0;
	string s;
	cin >> s;
	map <int, int> cnt;
	cnt[0] = 1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			bal++;
		} else {
			bal--;
		}
		cnt[bal]++;
	}
	cnt[bal]--;
	int res = 0;
	if (!bal && cnt[x]) {
		cout << "-1\n";
		return;
	}
	if (!bal) {
		cout << "0\n";
		return;
	}
	int step = abs(bal);
	int sgn = (bal > 0 ? 1 : -1);
	bal = 0;
	for (int i = 0; i < n; i++) {
		if ((x - bal) % step == 0) {
			if (bal < x && sgn == -1) {
				if (s[i] == '0') {
					bal++;
				} else {
					bal--;
				}
				continue;
			}
			if (bal > x && sgn == 1) {
				if (s[i] == '0') {
					bal++;
				} else {
					bal--;
				}
				continue;
			}
			res++;
		}
		if (s[i] == '0') {
			bal++;
		} else {
			bal--;
		}

		//cout << x << " " << bal << " " << step << endl;
	}
	cout << res << "\n";
}

main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

}