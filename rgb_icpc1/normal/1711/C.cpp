#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define endl '\n'
#define sz(x) (LL)(x.size())

template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long LL;

const LL MX = 500005;

LL Tc;
LL a[MX];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> Tc;
	while(Tc--) {
		LL n, m, k;
		cin >> n >> m >> k;
		for (LL i = 0; i < k; i ++) cin >> a[i];
		LL flg = 0;
		LL cnt = 0;
		int f = 0;
		for (LL i = 0; i < k; i ++) {
			if (a[i] / n >= 2) {
				cnt += a[i] / n;
				if ((a[i] / n) > 2) f = 1;
			}
		}
		if (cnt >= m) {
			if (m & 1) {
				if (f) flg = 1;
			}
			else flg = 1;
		}
		swap(n, m);
		cnt = 0;
		f = 0;
		for (LL i = 0; i < k; i ++) {
			if (a[i] / n >= 2) {
				cnt += a[i] / n;
				if ((a[i] / n) > 2) f = 1;
			}
		}
		if (cnt >= m) {
			if (m & 1) {
				if (f) flg = 1;
			}
			else flg = 1;
		}
		if (flg) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}