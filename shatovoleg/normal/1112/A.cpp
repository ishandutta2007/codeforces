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

void run() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> mx(m, 0);
	vector<int> p(n);
	vector<int> s(n);
	for (auto &x : p)
		cin >> x;
	for (auto &x : s)
		cin >> x;
	for (int i = 0; i < n; ++i) {
		--s[i];
		cmax(mx[s[i]], p[i]);
	}
	int cnt = 0;
	for (int i = 0; i < k; ++i) {
		int v;
		cin >> v;
		--v;
		if (p[v] != mx[s[v]])
			++cnt;
	}
	cout << cnt << endl;
}