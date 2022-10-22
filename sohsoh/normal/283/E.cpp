
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define all(x)                      (x).begin(),(x).end()

const ll N = 1e6;

int sg[N], n, k;
ll deg[N], ans;
bool lz[N];
vector<int> L[N], R[N], S;

inline void push(int l, int r, int v) {
	if (lz[v]) {
		sg[v] = r - l + 1 - sg[v];
		lz[v << 1] ^= 1;
		lz[v << 1 | 1] ^= 1;
		lz[v] = false;
	}
}


int query(int ql, int qr, bool b, int l = 1, int r = n, int v = 1) {
	push(l, r, v);
	int t = min(qr, r) - max(ql, l) + 1;
	if (t <= 0) return 0;
	if (t == r - l + 1) {
		int ans = sg[v];
		lz[v] ^= b;
		push(l, r, v);
		return ans;
	}

	int mid = (l + r) >> 1, ans = 0;
	ans += query(ql, qr, b, l, mid, v << 1);
	ans += query(ql, qr, b, mid + 1, r, v << 1 | 1);
	if (b) sg[v] += t - 2 * ans;
	return ans;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		S.push_back(x);
	}

	sort(all(S));
	for (int i = 0; i < k; i++) {
		int l, r;
		cin >> l >> r;
		l = lower_bound(all(S), l) - S.begin() + 1;
		r = lower_bound(all(S), r + 1) - S.begin();

		if (l > r) continue;

		L[l].push_back(r);
		R[r].push_back(l);
	}

	for (int i = 1; i <= n; i++) {
		if (L[i].size() & 1) query(i, n, true);
		deg[i] += query(1, i - 1, false);
		
		for (int l : R[i]) query(l, n, true);
	} 

	for (int i = 0; i < N; i++)
		sg[i] = 0, lz[i] = false;

	for (int i = n; i > 0; i--) {
		if (R[i].size() & 1) query(1, i, true);
		deg[i] += n - i - query(i + 1, n, false);
		
		for (int r : L[i])
			query(1, r, true);
	}

	ans = 1ll * n * (n - 1) * (n - 2) / 6;
	for (int i = 1; i <= n; i++)
		ans -= deg[i] * (deg[i] - 1) / 2;
	cout << ans << endl;
	return 0;
}