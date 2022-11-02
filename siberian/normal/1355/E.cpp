#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll
int n, A, B, M;
vector<int> a;

void read() {
	cin >> n >> A >> B >> M;
	a.resize(n);
	for (auto &i : a) {
		cin >> i;
	}
	sort(all(a));
}

const int INF = 1e18 + 228;
int ans = INF;
int sum = 0;

vector<int> pref;

int get_cost(int x) {
	int pos = --upper_bound(all(a), x) - a.begin();
	int L = (pos >= 0 ? pref[pos] : 0);
	int R = sum - L;
	L = x * (pos + 1) - L;
	R = R - x * (n - (pos + 1));
	int cost = 0;
	if (A + B > M) {
		int add = min(L, R);
		cost += add * M;
		L -= add;
		R -= add;
	}
	cost += L * A;
	cost += R * B;
	return cost;
}

int get(int l, int r) {
	while (l < r - 2) {
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;
		if (get_cost(mid1) > get_cost(mid2))
			l = mid1;
		else
			r = mid2;
	}
	int ans = INF;
	for (int i = l; i <= r; i++) {
		chkmin(ans, get_cost(i));
	}
	return ans;
}

void run() {
	pref = a;
	for (int i = 1; i < n; i++) {
		pref[i] += pref[i - 1];
	}
	for (auto i : a) {
		sum += i;
	}
	for (int i = 0; i < n; i++) {
		chkmin(ans, get_cost(a[i]));
	}
	for (int i = 0; i < n - 1; i++) {
		chkmin(ans, get(a[i], a[i + 1]));
	}
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}