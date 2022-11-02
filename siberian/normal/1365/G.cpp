#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int Q = 13;

vector<int> have;

void build() {
	for (int mask = 0; mask < (1 << Q); mask++) {
		if (__builtin_popcount(mask) == 6) {
			have.push_back(mask);
		}
	}
}

ll get(vector<int> a) {
	if (a.empty()) return 0;
	cout << "? " << a.size();
	for (auto i : a) cout << " " << i + 1;
	cout << endl;
	ll ans;
	cin >> ans;
	return ans;
}

void out_ans(vector<ll> ans) {
	cout << "!";
	for (auto i : ans) cout << " " << i;
	cout << endl;
	exit(0);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	build();
	int n;
	cin >> n;	
	vector<vector<int>> q(Q);
	vector<ll> qAns;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < Q; j++) {
			if ((have[i] >> j) & 1) {
				q[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < Q; i++) {
		qAns.push_back(get(q[i]));
	}
	vector<ll> ans;
	for (int i = 0; i < n; i++) {
		ll fans = 0;
		for (int j = 0; j < Q; j++) {
			if ((have[i] >> j) & 1) continue;
			fans |= qAns[j];
		}
		ans.push_back(fans);
	}
	out_ans(ans);
	return 0;
}