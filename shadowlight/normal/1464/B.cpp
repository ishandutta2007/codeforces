#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const ll INF = 1e18 + 7;

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	ll n = s.size();
	ll x, y;
	cin >> x >> y;

	vector <pair <int, int>> cnt_pref(n + 1), cnt_suf(n + 1);
	for (int i = 0; i < n; ++i) {
		cnt_pref[i + 1] = cnt_pref[i];
		if (s[i] == '0') {
			cnt_pref[i + 1].x++;
		} else if (s[i] == '1') {
			cnt_pref[i + 1].y++;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		cnt_suf[i] = cnt_suf[i + 1];
		if (s[i] == '0') {
			cnt_suf[i].x++;
		} else if (s[i] == '1') {
			cnt_suf[i].y++;
		}
	}

	ll global_add = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			global_add += cnt_pref[i].y * y;
			global_add += cnt_suf[i + 1].y * x;
		} else if (s[i] == '1') {
			global_add += cnt_pref[i].x * x;
			global_add += cnt_suf[i + 1].x * y;
		}
	}
	global_add /= 2;


	ll res = INF;

	for (int d = 0; d < 2; ++d) {
		int now = 0;
		vector <ll> lsums(n + 1, 0), rsums(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			if (s[i] != '?') continue;
			++now;
			lsums[now] = lsums[now - 1];
			if (d) {
				lsums[now] += cnt_pref[i].x * x;
				lsums[now] += cnt_suf[i].x * y; 
			} else {
				lsums[now] += cnt_pref[i].y * y;
				lsums[now] += cnt_suf[i].y * x;
			}
		}
		now = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (s[i] != '?') continue;
			++now;
			rsums[now] = rsums[now - 1];
			if (!d) {
				rsums[now] += cnt_pref[i].x * x;
				rsums[now] += cnt_suf[i].x * y; 
			} else {
				rsums[now] += cnt_pref[i].y * y;
				rsums[now] += cnt_suf[i].y * x;
			}
		}
		for (int cnt = 0; cnt <= now; ++cnt) {
			//cout << cnt << " " << lsums[cnt] << " " << rsums[now - cnt] << "\n";
			res = min(res, lsums[cnt] + rsums[now - cnt] + cnt * (ll) (now - cnt) * (d ? y : x));
		}
	}
	cout << res + global_add << "\n";
}