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

int get_perc(int n, int m) {
	n *= 100;
	int d = n / m;
	n %= m;
	if (2 * n >= m)
		++d;
	return d;
}

void run() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}
	vector<int> beg(n, 0);
	vector<int> inv(k, 0);
	vector<int> times;
	for (int i = 0; i < n; ++i) {
		int mn = inv[0], mni = 0;
		for (int j = 0; j < k; ++j) {
			if (cmin(mn, inv[j])) {
				mni = j;
			}
		}
		times.pb(mn + a[i]);
		beg[i] = mn;
		inv[mni] += a[i];
	}
	sort(all(times));
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= a[i]; ++j) {
			if (j == get_perc(lower_bound(all(times), beg[i] + j) - times.begin(), n)) {
				// j + 1 == get_perc(upper_bound(all(times), beg[i] + j) - times.begin() + 1, n)) {
				++cnt;
				break;
			}
		}
	}
	cout << cnt << endl;
}