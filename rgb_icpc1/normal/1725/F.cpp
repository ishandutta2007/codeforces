#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MN 100005
#define bit(x) (1 << (x))

int ans[MN], st[MN], en[MN];
int L[MN], R[MN], v[3 * MN];

vector <int> V;

int main () {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, k;
	cin >> N;
	for (int i = 0; i < N; i ++) {
		cin >> L[i] >> R[i];
		L[i] --; R[i] --;
	}
	for (int i = 0; i <= 30; i ++) {
		V.clear();
		for (int j = 0; j < N; j ++) {
			st[j] = L[j] % bit(i);
			int len = R[j] - L[j];
			if (len >= bit(i) - 1) {
				st[j] = 0; en[j] = bit(i) - 1;
			} else {
				if (st[j] + len >= bit(i)) en[j] = (st[j] + len) % bit(i);
				else en[j] = st[j] + len;
			}
			V.push_back(st[j]); V.push_back(en[j]);
		}
		V.push_back(0); V.push_back(bit(i) - 1);
		sort (V.begin(), V.end());
		V.erase(unique(V.begin(), V.end()), V.end());
		int VN = V.size(), cur = 0;
		for (int j = 0; j < N; j ++) {
			if (st[j] <= en[j]) {
				k = lower_bound(V.begin(), V.end(), st[j]) - V.begin() + 1; v[k] ++;
				k = lower_bound(V.begin(), V.end(), en[j]) - V.begin() + 2; v[k] --;
			} else {
				k = lower_bound(V.begin(), V.end(), st[j]) - V.begin() + 1; v[k] ++; v[VN + 1] --;
				k = lower_bound(V.begin(), V.end(), en[j]) - V.begin() + 2; v[1] ++; v[k] --;
			}
		}
		for (int j = 0; j <= VN + 2; j ++) {
			cur += v[j];
			ans[i] = max(ans[i], cur);
			v[j] = 0;
		}
	}
	int q, w; cin >> q;
	while (q --) {
		cin >> w;
		cout << ans[__builtin_ctz(w)] << endl;
	}

	return 0;
}