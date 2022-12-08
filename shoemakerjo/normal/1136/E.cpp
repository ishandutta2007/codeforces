#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int maxn = 100010;

int n, q;
ll nums[maxn];
ll k[maxn];

set<int> inactive;

ll lazy[maxn*4];
ll seg[maxn*4]; //store the values

void delaze(int ss, int se, int si) {
	seg[si] += (se-ss+1) * lazy[si];
	if (ss != se) {
		lazy[si*2+1] += lazy[si];
		lazy[si*2+2] += lazy[si];
	}
	lazy[si] = 0;
}

void upd(int us, int ue, ll diff, int ss = 1, int se = n, int si = 0) {

	delaze(ss, se, si);

	if (us > ue || ss > se || us > se || ue < ss) return;

	if (us <= ss && se <= ue) {
		lazy[si] += diff;
		delaze(ss, se, si);
		return;
	}
	int mid = (ss+se)/2;
	upd(us, ue, diff, ss, mid, si*2+1);
	upd(us, ue, diff, mid+1, se, si*2+2);
	seg[si] = seg[si*2+1] + seg[si*2+2];
}

ll query(int qs, int qe, int ss = 1, int se = n, int si = 0) {
	delaze(ss, se, si);

	if (qs > qe || ss > se || qs > se || qe < ss) return 0LL;

	if (qs <= ss && se <= qe) return seg[si];

	int mid = (ss+se)/2;
	return query(qs, qe, ss, mid, si*2+1) + 
		query(qs, qe, mid+1, se, si*2+2);
}

void ch(int spot, ll val) {

	//find first inactive after me

	if (inactive.upper_bound(spot) == inactive.end()) {
		upd(spot, n, val);
		return;
	}

	int sp = *inactive.upper_bound(spot);

	upd(spot, sp-1, val);

	ll v1 = query(sp, sp);
	ll v2 = query(sp-1, sp-1) + k[sp-1];

	if (v1 < v2) {

		inactive.erase(inactive.find(sp));
		ch(sp, v2-v1);

	}
}

void buildseg(int ss = 1, int se = n, int si = 0) {
	if (ss == se) {
		seg[si] = nums[ss];
		return;
	}
	int mid = (ss+se)/2;
	buildseg(ss, mid, si*2+1);
	buildseg(mid+1, se, si*2+2);
	seg[si] = seg[si*2+1] + seg[si*2+2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		inactive.insert(i);
	}
	for (int i = 1; i <= n-1; i++) {
		cin >> k[i];
	}

	buildseg();

	cin >> q;
	string tp;

	int spot, l, r;
	ll x;

	while (q--) {
		cin >> tp;
		if (tp == "+") {
			cin >> spot >> x;
			ch(spot, x);
			inactive.insert(spot);
		}
		else {
			cin >> l >> r;
			cout << query(l, r) << '\n';
		}
	}
	cout.flush();
}