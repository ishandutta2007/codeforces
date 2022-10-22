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
	
	mx = 0;
	for (int i = 0; i < n; ++i) {
		if (cnt[i] > cnt[mx]) {
			mx = i;
		}
	}

	vector <int> mx_pos = {-1};
	for (int i = 0; i < n; ++i) {
		if (a[i] == mx) {
			mx_pos.pb(i);
		}
	}

	vector <int> lowest(2 * n, n);
	int res = 0;

	for (int k = 0; k < 100; ++k) {
		if (k == mx) continue;

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


	cout << res << "\n";

}