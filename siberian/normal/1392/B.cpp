#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll

int n;
int k;
vector<int> a;

void make() {
	int x = *max_element(all(a));
	for (auto &i : a) {
		i = x - i;
	}
}

void solve() {
	cin >> n >> k;
	a.resize(n);
	for (auto &i : a) {
		cin >> i;
	}
	make();
	k--;
	k %= 2;
	if (k) make();
	for (auto i : a) {
		cout << i << " ";
	}
	cout << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}