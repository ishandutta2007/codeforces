#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


vector <deque<int>> lens;
vector <int> counts;

int n;
vector <int> a;
int mx;
int res = 0;

const int SQ = sqrt(2e5 + 7);

int find_pos(int it, vector<pair<int, int>>& segs, vector<int> &pref) {
	if (it >= pref.back()) {
		return -1;
	}
	int l = 0, r = segs.size();
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (pref[mid] > it) {
			r = mid;
		} else {
			l = mid;
		}
	}
	return l;
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector <int> cnt(n, 0);
	a.resize(n);
	vector <vector<int>> pos(n);


	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
		++cnt[a[i]];
		pos[a[i]].pb(i);
	}

	for (int i = 0; i < n; ++i) {
		pos[i].pb(n);
	}
	
	mx = 0;
	for (int i = 0; i < n; ++i) {
		if (cnt[i] > cnt[mx]) {
			mx = i;
		}
	}

	vector <int> mx_pos;
	mx_pos.pb(-1);
	for (int i = 0; i < n; ++i) {
		if (a[i] == mx) {
			mx_pos.pb(i);
		}
	}

	vector <int> lowest(2 * n, n);
	int res = 0;

	for (int k = 0; k < n; ++k) {
		if (k == mx) continue;
		if (cnt[k] < SQ) continue;

		int bal = n;
		lowest[bal] = -1;

		for (int i = 0; i < n; ++i) {
			if (a[i] == mx) {
				--bal;
			} else if (a[i] == k) {
				++bal;
			}
			lowest[bal] = min(lowest[bal], i);
			res = max(res, i - lowest[bal]);
		}

		bal = n;
		for (int i = 0; i < n; ++i) {
			if (a[i] == mx) {
				--bal;
			} else if (a[i] == k) {
				++bal;
			}
			lowest[bal] = n;
		}
	}

	for (int k = 0; k < n; ++k) {
		if (k == mx) continue;
		if (cnt[k] >= SQ) continue;
		int pr = -1;
		for (int now = 0; now < pos[k].size(); ++now) {
			for (int d = 0; d < 2; ++d) {
				int x = pos[k][now];
				int it = lower_bound(all(mx_pos), x) - mx_pos.begin();
				
				int bal = n;
				int total = 0;
				for (int i = max(it - cnt[k] - 1, 0); i < it; ++i) {
					if (mx_pos[i] < pr) {
						continue;
					}
					if (i) {
						--bal;
					}
					if (!d) {
						lowest[bal] = mx_pos[i];
					} else {
						lowest[bal] = n;
					}
				}
				++bal;
				if (!d) {
					lowest[bal] = min(lowest[bal], x);
				} else {
					lowest[bal] = n;
				}
				for (int nxt = now + 1; nxt < pos[k].size(); ++nxt) {
					int y = pos[k][nxt];
					while (total < cnt[k] + 1 && it < mx_pos.size() && mx_pos[it] < y) {
						if (!d) {
							res = max(res, mx_pos[it] - 1 - lowest[bal]);
						}
						--bal;
						if (!d) {
							lowest[bal] = min(lowest[bal], mx_pos[it]);
						} else {
							lowest[bal] = n;
						}
						++it, ++total;
					}
					if (total == cnt[k] + 1) {
						break;
					}
					if (!d) {
						lowest[bal] = min(lowest[bal], y - 1);
						res = max(res, (y - 1) - lowest[bal]);
						//cout << x << " " << y << " " << (y - 1) - lowest[bal] << "\n";
					} else {
						lowest[bal] = n;
					}
					++bal;
					if (!d) {
						lowest[bal] = min(lowest[bal], y);
						if (y != n) {
							res = max(res, y - lowest[bal]);
						}
					} else {
						lowest[bal] = n;
					}
				}
			}
			pr = pos[k][now];
		}
	}

	cout << res << "\n";

}