#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
#define pb push_back
#define kek pop_back
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pii pair<int, int>

#ifdef LOCAL
#define debug(x) cout << #x << " = " << x << endl;
#else
#define debug(x) ;
#endif

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

void run();

signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

void NO() {
	cout << -1 << endl;
	exit(0);
}

void run() {
	int m, k, n, s;
	cin >> m >> k >> n >> s;
	vector<int> a(m);
	for (auto &x : a)
		cin >> x;
	map<int, int> must_be;
	for (int i = 0; i < s; ++i) {
		int v;
		cin >> v;
		++must_be[v];
	}
	map<int, int> cur;
	int bad_cnt = len(must_be);
	// for (auto &x : a) {
	// 	++cur[x];
	// 	if (cur[x] == must_be[x])
	// 		--bad_cnt;
	// }
	int diff = m - (n - 1) * k;
	for (int i = 0; i < diff; ++i) {
		++cur[a[i]];
		if (cur[a[i]] == must_be[a[i]])
			--bad_cnt;
	}
	for (int i = 0; i < m; ++i) {
		if (i % k == 0 && bad_cnt == 0) {
			int cnt = min(m, i + diff) - i - k;
			if (cnt < 0) {
				continue;
			}
			cout << cnt << endl;
			for (int j = i; cnt > 0; ++j) {
				if (cur[a[j]] > must_be[a[j]]) {
					--cur[a[j]];
					cout << j + 1 << " ";
					--cnt;
				}
			}
			cout << endl;
			return;
		}
		if (cur[a[i]] == must_be[a[i]])
			++bad_cnt;
		--cur[a[i]];
		if (i + diff < m) {
			++cur[a[i + diff]];
			if (cur[a[i + diff]] == must_be[a[i + diff]]) {
				--bad_cnt;
			}
		}
	}
	NO();
}