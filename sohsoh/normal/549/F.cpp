#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int ps[MAXN], n, k, A[MAXN];
vector<int> oc[MAXN];
ll ans;

namespace segment {	
	pll sg[MAXN << 1];
	void build(int l = 1, int r = n, int v = 1) {
		if (l == r) sg[v] = {A[l], l};
		else {
			int mid = (l + r) >> 1;
			build(l, mid, v << 1);
			build(mid + 1, r, v << 1 | 1);
			sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
		}
	}

	pll query(int ql, int qr, int l = 1, int r = n, int v = 1) {
		if (ql > r || qr < l) return {-1, -1};
		if (ql <= l && qr >= r) return sg[v];
		
		int mid = (l + r) >> 1;
		return max(query(ql, qr, l, mid, v << 1),
				query(ql, qr, mid + 1, r, v << 1 | 1));
	}
}

inline int query(int x, int l, int r) {
	l--;
	return upper_bound(all(oc[x]), r) - upper_bound(all(oc[x]), l);
}

inline void solve(int l = 1, int r = n) {
	if (r < l) return;
	if (l == 0) exit(0);
	int mid = segment::query(l, r).Y;

	if (mid - l < r - mid) {
		for (int i = l - 1; i < mid; i++)
			ans += query((ps[i] + A[mid]) % k, mid, r);	
	} else {
		for (int i = mid; i <= r; i++) {
			ans += query((ps[i] - A[mid] % k + k) % k, l - 1, mid - 1);
		}
	}

	solve(l, mid - 1);
	solve(mid + 1, r);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	oc[0].push_back(0);

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		ps[i] = (ps[i - 1] + A[i]) % k;
		oc[ps[i]].push_back(i);
	}

	segment::build();
	solve();
	cout << ans - n << endl;
	return 0;
}