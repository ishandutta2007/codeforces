#include <bits/stdc++.h>

using namespace std;

#define maxn 100010

int diff[maxn];
int ct[maxn];
int seg[maxn*4];
int n, m;
int inc[maxn];
int decr[maxn];

void up(int spot, int val, int ss, int se, int si) {
	if (ss > se || spot > se || spot < ss) return;
	if (spot == ss && spot == se) {
		seg[si] = max(seg[si], val);
		return;
	}
	int mid = (ss+se)/2;
	if (spot <= mid) {
		up(spot, val, ss, mid, si*2+1);
	}
	else up(spot, val, mid+1, se, si*2+2);
	seg[si] = max(seg[si*2+1], seg[si*2+2]);
}

void update(int spot, int val) {
	up(spot, val, 0, n, 0);
}


int qu(int qs, int qe, int ss, int se, int si) {
	if (qs > qe || ss > se || qs > se || qe < ss) return 0;
	if (qs <= ss && se <= qe) return seg[si];
	int mid = (ss+se)/2;
	return max(qu(qs, qe, ss, mid, si*2+1),
		qu(qs, qe, mid+1, se, si*2+2));
}

int query(int qs, int qe) {
	return qu(qs, qe, 0, n, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	fill(diff, diff+maxn, 0);
	int l, r;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		diff[l]++;
		diff[r+1]--;
	}
	fill(seg, seg+maxn*4, 0);
	int cur = 0;
	for (int i = 1; i <= m; i++) {
		cur += diff[i];
		ct[i] = cur;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int val = query(0, ct[i])+1;
		inc[i] = val;
		update(ct[i], val);
	}
	fill(seg, seg+maxn*4, 0);
	for (int i = m; i >= 1; i--) {
		int val = query(0, ct[i])+1;
		decr[i] = val;
		update(ct[i], val);
	}
	for (int i = 1; i <= m; i++) {
		ans = max(ans, inc[i]+decr[i]-1);
	}
	cout << ans << endl;
	cin >> ans;

}